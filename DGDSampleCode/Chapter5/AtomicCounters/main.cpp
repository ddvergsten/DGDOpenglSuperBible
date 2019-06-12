//This example demonstrates using an atomic counter "thread safe" inside a shader.
//also demonstrates switching between shader programs, and having the uniform from
//one shader available in the 2nd shader program just because the common buffer is bound
//to binding point 0.  Both shaders uniform variable "area" is also bound to binding point 0
//as a result, switching from 1 program to the other, the data from shader 1 is available in shader 2.
#define _LINUX
#include <sb7.h>
#include <vmath.h>
#include <vector>
#include <iostream>
//// Remove this to draw only a single cube!
//#define MANY_CUBES

//static const float positions[] = {
//    0.25, -0.25, 0.5, 1.0,
//    -0.25, -0.25, 0.5, 1.0,
//    0.25, 0.25, 0.5, 1.0
//};
class mix_app : public sb7::application
{
public:
    mix_app()
    {

    }

    void init()
    {
        static const char title[] = "OpenGL SuperBible - Mix Application";

        sb7::application::init();

        memcpy(info.title, title, sizeof(title));
    }

    virtual void startup()
    {

        //render a triangle "hard coded"
        static const char * vs_source[] =
        {
            "#version 450 core                                                      \n"
            "                                                                       \n"
            "void main(void)                                                        \n"
            "{                                                                      \n"
            "    const vec4 vertices[3] = vec4[3](vec4( -0.25, -0.25, 0.5, 1.0),    \n"
            "                                   vec4(0.0, 0.25, 0.5, 1.0),          \n"
            "                                   vec4( 0.25,  -0.25, 0.5, 1.0));     \n"
            "                                                                       \n"
            "    gl_Position = vertices[gl_VertexID];                               \n"
            "}                                                                      \n"
        };

        //this shaders var "area" is bound to the same uniform buffer binding point
        //as "area" in the other fragment shader, so all we need to do is
        //switch "programs" below and the data from fs_source is available in this shader
        static const char * fsdraw_source[] =
        {
            "#version 450 core                                              \n"
            "layout (binding = 0, offset = 0) uniform atomic_uint area;     \n"
            "out vec4 color;                                                \n"
            "void main(void)                                                \n"
            "{                                                              \n"
            "   uint aval = atomicCounter(area);                            \n"
            "   float fval = float(aval) / 1000000.0;                       \n"
            "   color = vec4(1.0, fval, 0.0, 1.0);                          \n"
            "}"
        };

        //this shader just counts how many times the fragment shader is called
        //ie how many pixels are in the triangle we're rendering from the vertex shader above
        static const char * fs_source[] =
        {
            "#version 450 core                                              \n"
            "layout (binding = 0, offset = 0) uniform atomic_uint area;     \n"
            "out vec4 color;                                                \n"
            "void main(void)                                                \n"
            "{                                                              \n"
            "       atomicCounterIncrement(area);                           \n"
            "}                                                              \n"
        };

        //compile our shaders
        GLint isCompiled = -1;
        program = glCreateProgram();
        GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fs, 1, fs_source, NULL);
        glCompileShader(fs);
        glGetShaderiv(fs, GL_COMPILE_STATUS, &isCompiled);

        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> errorLog(maxLength);
            glGetShaderInfoLog(fs, maxLength, &maxLength, &errorLog[0]);

            // Provide the infolog in whatever manor you deem best.
            // Exit with failure.
            glDeleteShader(fs); // Don't leak the shader.
            return;
        }

        GLuint vs = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vs, 1, vs_source, NULL);
        glCompileShader(vs);
        glGetShaderiv(vs, GL_COMPILE_STATUS, &isCompiled);
        GLint maxLength;
        //unsigned char errorLog[1024];
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> errorLog(maxLength);
            glGetShaderInfoLog(vs, maxLength, &maxLength, &errorLog[0]);

            // Provide the infolog in whatever manor you deem best.
            // Exit with failure.
            glDeleteShader(vs); // Don't leak the shader.
            return;
        }

        glAttachShader(program, vs);

        glAttachShader(program, fs);

        glLinkProgram(program);

        //compile 2nd set of shaders into a program that will
        //do the actual drawing
        isCompiled = -1;
        programdraw = glCreateProgram();
        GLuint fsdraw = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fsdraw, 1, fsdraw_source, NULL);
        glCompileShader(fsdraw);
        glGetShaderiv(fsdraw, GL_COMPILE_STATUS, &isCompiled);

        //error checking/messages
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(fsdraw, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> errorLog(maxLength);
            glGetShaderInfoLog(fsdraw, maxLength, &maxLength, &errorLog[0]);

            // Provide the infolog in whatever manor you deem best.
            // Exit with failure.
            glDeleteShader(fsdraw); // Don't leak the shader.
            return;
        }
        //error checking/messages
        GLuint vsdraw = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vsdraw, 1, vs_source, NULL);
        glCompileShader(vsdraw);
        glGetShaderiv(vsdraw, GL_COMPILE_STATUS, &isCompiled);
        if(isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(vsdraw, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> errorLog(maxLength);
            glGetShaderInfoLog(vsdraw, maxLength, &maxLength, &errorLog[0]);

            // Provide the infolog in whatever manor you deem best.
            // Exit with failure.
            glDeleteShader(vsdraw); // Don't leak the shader.
            return;
        }

        glAttachShader(programdraw, vsdraw);
        glAttachShader(programdraw, fsdraw);

        glLinkProgram(programdraw);

        //create our atomic counter/buffer and bind to binding point 0
        glCreateVertexArrays(1, &vao);
        glBindVertexArray(vao);

        GLuint buf;
        glGenBuffers(1, &buf);
        glBindBuffer(GL_ATOMIC_COUNTER_BUFFER, buf);
        glBufferData(GL_ATOMIC_COUNTER_BUFFER, 16 * sizeof(GLuint),
                     NULL, GL_DYNAMIC_COPY);

        glBindBufferBase(GL_ATOMIC_COUNTER_BUFFER, 0, buf);

        glBindBuffer(GL_ATOMIC_COUNTER_BUFFER, buf);
        const GLuint zero = 0;
        glBufferSubData(GL_ATOMIC_COUNTER_BUFFER, 2 * sizeof(GLuint), sizeof(GLuint), &zero);
    }

    virtual void render(double currentTime)
    {
        static const GLfloat green[] = { 0.0f, 0.25f, 0.0f, 1.0f };

        glViewport(0, 0, info.windowWidth, info.windowHeight);
        glClearBufferfv(GL_COLOR, 0, green);

        glUseProgram(program);
        //don't actually output any pixels from this shader because for this example
        //it is just counting the number of pixels in it's var "area"
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //we're going to use the 2nd fragment shader to do the actual drawing
        //it's going to use the counter "area" from the other shader to output it's pixel value
        glUseProgram(programdraw);
        //turn on color output
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        GLuint areaindex = glGetUniformBlockIndex(programdraw, "area_block");
        glUniformBlockBinding(programdraw, areaindex, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);

    }

    virtual void shutdown()
    {
        glDeleteVertexArrays(1, &vao);
        glDeleteProgram(program);
//        glDeleteBuffers(1, &position_buffer);
    }

    virtual void onKey(int key, int action)
    {
//        if (action == 1)
//        {
//            switch (key)
//            {
//                case 'W':   wireframe_mode = !wireframe_mode;
//                    break;
//            }
//        }
    }

private:
    GLuint buffers[2];
    GLuint          program;
    GLuint          programdraw;
    GLuint          vao;
//    GLuint          position_buffer;
//    GLuint          index_buffer;
    GLint           mv_location;
    GLint           proj_location;


};

DECLARE_MAIN(mix_app)



///*
// * Copyright © 2012-2015 Graham Sellers
// *
// * Permission is hereby granted, free of charge, to any person obtaining a
// * copy of this software and associated documentation files (the "Software"),
// * to deal in the Software without restriction, including without limitation
// * the rights to use, copy, modify, merge, publish, distribute, sublicense,
// * and/or sell copies of the Software, and to permit persons to whom the
// * Software is furnished to do so, subject to the following conditions:
// *
// * The above copyright notice and this permission notice (including the next
// * paragraph) shall be included in all copies or substantial portions of the
// * Software.
// *
// * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
// * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// * DEALINGS IN THE SOFTWARE.
// */
//#define _LINUX
//#include <sb7.h>
//#include <sb7color.h>
//#include <vmath.h>

//class basicfbo_app : public sb7::application
//{
//    void init()
//    {
//        static const char title[] = "OpenGL SuperBible - Basic Framebuffer Object";

//        sb7::application::init();

//        memcpy(info.title, title, sizeof(title));
//    }

//    virtual void startup()
//    {
//        static const char * vs_source[] =
//        {
//            "#version 410 core                                                  \n"
//            "                                                                   \n"
//            "layout (location = 0) in vec4 position;                            \n"
//            "layout (location = 1) in vec2 texcoord;                            \n"
//            "                                                                   \n"
//            "out VS_OUT                                                         \n"
//            "{                                                                  \n"
//            "    vec4 color;                                                    \n"
//            "    vec2 texcoord;                                                 \n"
//            "} vs_out;                                                          \n"
//            "                                                                   \n"
//            "uniform mat4 mv_matrix;                                            \n"
//            "uniform mat4 proj_matrix;                                          \n"
//            "                                                                   \n"
//            "void main(void)                                                    \n"
//            "{                                                                  \n"
//            "    gl_Position = proj_matrix * mv_matrix * position;              \n"
//            "    vs_out.color = position * 2.0 + vec4(0.5, 0.5, 0.5, 0.0);      \n"
//            "    vs_out.texcoord = texcoord;                                    \n"
//            "}                                                                  \n"
//        };

//        static const char * fs_source1[] =
//        {
//            "#version 410 core                                                              \n"
//            "                                                                               \n"
//            "in VS_OUT                                                                      \n"
//            "{                                                                              \n"
//            "    vec4 color;                                                                \n"
//            "    vec2 texcoord;                                                             \n"
//            "} fs_in;                                                                       \n"
//            "                                                                               \n"
//            "out vec4 color;                                                                \n"
//            "                                                                               \n"
//            "void main(void)                                                                \n"
//            "{                                                                              \n"
//            "   color = vec4(1.0,0.0,0.0,1.0);                                                      \n"
//            //"    color = sin(fs_in.color * vec4(40.0, 20.0, 30.0, 1.0)) * 0.5 + vec4(0.5);  \n"
//            "}                                                                              \n"
//        };

//        static const char * fs_source2[] =
//        {
//            "#version 420 core                                                              \n"
//            "                                                                               \n"
//            "uniform sampler2D tex;                                                         \n"
//            "                                                                               \n"
//            "out vec4 color;                                                                \n"
//            "                                                                               \n"
//            "in VS_OUT                                                                      \n"
//            "{                                                                              \n"
//            "    vec4 color;                                                                \n"
//            "    vec2 texcoord;                                                             \n"
//            "} fs_in;                                                                       \n"
//            "                                                                               \n"
//            "void main(void)                                                                \n"
//            "{                                                                              \n"
//            //"    color = mix(fs_in.color, texture(tex, fs_in.texcoord), 0.7);               \n"
//            "       vec4 colort = texture(tex, fs_in.texcoord);                                   \n"
//            "       color = vec4(colort.x, colort.y, colort.z, 0.25);\n"
//            "}                                                                              \n"
//        };

//        program1 = glCreateProgram();
//        GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
//        glShaderSource(fs, 1, fs_source1, NULL);
//        glCompileShader(fs);

//        GLuint vs = glCreateShader(GL_VERTEX_SHADER);
//        glShaderSource(vs, 1, vs_source, NULL);
//        glCompileShader(vs);

//        glAttachShader(program1, vs);
//        glAttachShader(program1, fs);

//        glLinkProgram(program1);

//        glDeleteShader(vs);
//        glDeleteShader(fs);

//        program2 = glCreateProgram();
//        fs = glCreateShader(GL_FRAGMENT_SHADER);
//        glShaderSource(fs, 1, fs_source2, NULL);
//        glCompileShader(fs);

//        vs = glCreateShader(GL_VERTEX_SHADER);
//        glShaderSource(vs, 1, vs_source, NULL);
//        glCompileShader(vs);

//        glAttachShader(program2, vs);
//        glAttachShader(program2, fs);

//        glLinkProgram(program2);

//        glDeleteShader(vs);
//        glDeleteShader(fs);

//        mv_location = glGetUniformLocation(program1, "mv_matrix");
//        proj_location = glGetUniformLocation(program1, "proj_matrix");
//        mv_location2 = glGetUniformLocation(program2, "mv_matrix");
//        proj_location2 = glGetUniformLocation(program2, "proj_matrix");

//        glGenVertexArrays(1, &vao);
//        glBindVertexArray(vao);

//        static const GLushort vertex_indices[] =
//        {
//            0, 1, 2,
//            2, 1, 3,
//            2, 3, 4,
//            4, 3, 5,
//            4, 5, 6,
//            6, 5, 7,
//            6, 7, 0,
//            0, 7, 1,
//            6, 0, 2,
//            2, 4, 6,
//            7, 5, 3,
//            7, 3, 1
//        };

//        static const GLfloat vertex_data2[] =
//        {
//            -0.25f, -0.25f,  0.25f,      0.0f, 1.0f,
//            -0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//             0.25f, -0.25f, -0.25f,      1.0f, 0.0f,

//             0.25f, -0.25f, -0.25f,      1.0f, 0.0f,
//             0.25f, -0.25f,  0.25f,      1.0f, 1.0f,
//            -0.25f, -0.25f,  0.25f,      0.0f, 1.0f,

//             0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//             0.25f,  0.25f, -0.25f,      1.0f, 0.0f,
//             0.25f, -0.25f,  0.25f,      0.0f, 1.0f,

//             0.25f,  0.25f, -0.25f,      1.0f, 0.0f,
//             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,
//             0.25f, -0.25f,  0.25f,      0.0f, 1.0f,

//             0.25f,  0.25f, -0.25f,      1.0f, 0.0f,
//            -0.25f,  0.25f, -0.25f,      0.0f, 0.0f,
//             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,

//            -0.25f,  0.25f, -0.25f,      0.0f, 0.0f,
//            -0.25f,  0.25f,  0.25f,      0.0f, 1.0f,
//             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,

//            -0.25f,  0.25f, -0.25f,      1.0f, 0.0f,
//            -0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//            -0.25f,  0.25f,  0.25f,      1.0f, 1.0f,

//            -0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//            -0.25f, -0.25f,  0.25f,      0.0f, 1.0f,
//            -0.25f,  0.25f,  0.25f,      1.0f, 1.0f,
////this is our square
//            -0.25f,  0.25f, -0.25f,      0.0f, 1.0f,
//                0.25f, -0.25f, -0.25f,      1.0f, 0.0f,
//             0.25f,  0.25f, -0.25f,      1.0f, 1.0f,


//             0.25f, -0.25f, -0.25f,      1.0f, 0.0f,
//            -0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//            -0.25f,  0.25f, -0.25f,      0.0f, 1.0f,



//            -0.1f, -0.25f,  0.25f,      0.0f, 0.0f,
//             -0.1f, 0.25f,  0.25f,      1.0f, 0.0f,
//             0.1f,  0.25f,  0.25f,      1.0f, 1.0f,

//             0.1f,  0.25f,  0.25f,      1.0f, 1.0f,
//            0.1f,  -0.25f,  0.25f,      0.0f, 1.0f,
//            -0.1f, -0.25f,  0.25f,      0.0f, 0.0f,

//            -0.25f, -0.1f,  0.25f,      0.0f, 0.0f,
//             -0.25f, 0.1f,  0.25f,      1.0f, 0.0f,
//             0.25f,  0.1f,  0.25f,      1.0f, 1.0f,

//             0.25f,  0.1f,  0.25f,      1.0f, 1.0f,
//            0.25f,  -0.1f,  0.25f,      0.0f, 1.0f,
//            -0.25f, -0.1f,  0.25f,      0.0f, 0.0f,


////            -0.25f, -0.25f,  0.25f,      0.0f, 0.0f,
////             0.25f, -0.25f,  0.25f,      1.0f, 0.0f,
////             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,

////             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,
////            -0.25f,  0.25f,  0.25f,      0.0f, 1.0f,
////            -0.25f, -0.25f,  0.25f,      0.0f, 0.0f,
//        };
//        static const GLfloat vertex_data[] =
//        {
//             // Position                 Tex Coord
//            -0.25f, -0.25f,  0.25f,      0.0f, 1.0f,
//            -0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//             0.25f, -0.25f, -0.25f,      1.0f, 0.0f,

//             0.25f, -0.25f, -0.25f,      1.0f, 0.0f,
//             0.25f, -0.25f,  0.25f,      1.0f, 1.0f,
//            -0.25f, -0.25f,  0.25f,      0.0f, 1.0f,

//             0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//             0.25f,  0.25f, -0.25f,      1.0f, 0.0f,
//             0.25f, -0.25f,  0.25f,      0.0f, 1.0f,

//             0.25f,  0.25f, -0.25f,      1.0f, 0.0f,
//             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,
//             0.25f, -0.25f,  0.25f,      0.0f, 1.0f,

//             0.25f,  0.25f, -0.25f,      1.0f, 0.0f,
//            -0.25f,  0.25f, -0.25f,      0.0f, 0.0f,
//             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,

//            -0.25f,  0.25f, -0.25f,      0.0f, 0.0f,
//            -0.25f,  0.25f,  0.25f,      0.0f, 1.0f,
//             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,

//            -0.25f,  0.25f, -0.25f,      1.0f, 0.0f,
//            -0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//            -0.25f,  0.25f,  0.25f,      1.0f, 1.0f,

//            -0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//            -0.25f, -0.25f,  0.25f,      0.0f, 1.0f,
//            -0.25f,  0.25f,  0.25f,      1.0f, 1.0f,

//            -0.25f,  0.25f, -0.25f,      0.0f, 1.0f,
//             0.25f,  0.25f, -0.25f,      1.0f, 1.0f,
//             0.25f, -0.25f, -0.25f,      1.0f, 0.0f,

//             0.25f, -0.25f, -0.25f,      1.0f, 0.0f,
//            -0.25f, -0.25f, -0.25f,      0.0f, 0.0f,
//            -0.25f,  0.25f, -0.25f,      0.0f, 1.0f,

//            -0.25f, -0.25f,  0.25f,      0.0f, 0.0f,
//             0.25f, -0.25f,  0.25f,      1.0f, 0.0f,
//             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,

//             0.25f,  0.25f,  0.25f,      1.0f, 1.0f,
//            -0.25f,  0.25f,  0.25f,      0.0f, 1.0f,
//            -0.25f, -0.25f,  0.25f,      0.0f, 0.0f,
//        };

//        glGenBuffers(1, &position_buffer);
//        glBindBuffer(GL_ARRAY_BUFFER, position_buffer);
//        glBufferData(GL_ARRAY_BUFFER,
//                     sizeof(vertex_data),
//                     vertex_data,
//                     GL_STATIC_DRAW);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), NULL);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
//        glEnableVertexAttribArray(1);


//        glGenBuffers(1, &position_buffer2);
//        glBindBuffer(GL_ARRAY_BUFFER, position_buffer2);
//        glBufferData(GL_ARRAY_BUFFER,
//                     sizeof(vertex_data2),
//                     vertex_data2,
//                     GL_STATIC_DRAW);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), NULL);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
//        glEnableVertexAttribArray(1);

//        glBindBuffer(GL_ARRAY_BUFFER, position_buffer);
//        glGenBuffers(1, &index_buffer);
//        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
//        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
//                     sizeof(vertex_indices),
//                     vertex_indices,
//                     GL_STATIC_DRAW);

//       // glEnable(GL_CULL_FACE);

//        glEnable(GL_DEPTH_TEST);
//        glDepthFunc(GL_LEQUAL);

//        glGenFramebuffers(1, &fbo);
//        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

//        glGenTextures(1, &color_texture);
//        glBindTexture(GL_TEXTURE_2D, color_texture);
//        glTexStorage2D(GL_TEXTURE_2D, 9, GL_RGBA8, 512, 512);

//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//        glGenTextures(1, &depth_texture);
//        glBindTexture(GL_TEXTURE_2D, depth_texture);
//        glTexStorage2D(GL_TEXTURE_2D, 9, GL_DEPTH_COMPONENT32F, 512, 512);

//        glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, color_texture, 0);
//        glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depth_texture, 0);

//        static const GLenum draw_buffers[] = { GL_COLOR_ATTACHMENT0 };
//        glDrawBuffers(1, draw_buffers);
//    }

//    virtual void render(double currentTime)
//    {
//        static const GLfloat blue[] = { 0.0f, 0.0f, 0.3f, 1.0f };
//        static const GLfloat one = 1.0f;

//        vmath::mat4 proj_matrix = vmath::perspective(50.0f,
//                                                     (float)info.windowWidth / (float)info.windowHeight,
//                                                     0.1f,
//                                                     1000.0f);

//        float f = (float)currentTime * 0.3f;
//        vmath::mat4 mv_matrix2 = vmath::translate(0.0f, 0.0f, -1.0f) ;
//        vmath::mat4 mv_matrix = vmath::translate(0.0f, 0.0f, -1.0f) *
//                                vmath::translate(sinf(2.1f * f) * 0.5f,
//                                                    cosf(1.7f * f) * 0.5f,
//                                                    sinf(1.3f * f) * cosf(1.5f * f) * 2.0f) *
//                                vmath::rotate((float)currentTime * 45.0f, 0.0f, 1.0f, 0.0f) *
//                                vmath::rotate((float)currentTime * 81.0f, 1.0f, 0.0f, 0.0f);

//        ///////////////////////draw to fbo texture
//        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

//        glViewport(0, 0, 512, 512);
//        glClearBufferfv(GL_COLOR, 0, sb7::color::Blue);
//        glClearBufferfi(GL_DEPTH_STENCIL, 0, 1.0f, 0);

//        glUseProgram(program1);


//        glBindBuffer(GL_ARRAY_BUFFER, position_buffer2);

//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), NULL);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
//        glEnableVertexAttribArray(1);

//         //glDisable (GL_BLEND);

//        glUniformMatrix4fv(proj_location, 1, GL_FALSE, proj_matrix);
//        glUniformMatrix4fv(mv_location, 1, GL_FALSE, mv_matrix2);
//        //float lineWidth[2];
//        //glGetFloatv(GL_LINE_WIDTH_RANGE, lineWidth);
//        //glEnable(GL_LINE_SMOOTH);
//        //glEnable(GL_LINE_WIDTH);
//        //glLineWidth(10.0);

//        glDrawArrays(GL_TRIANGLES, 30, 12);
//        //glDrawArrays(GL_LINE_STRIP, 0, 3);

//        glBindFramebuffer(GL_FRAMEBUFFER, 0);

//        ////////////////////////////
//        /// \brief glViewport


//        glViewport(0, 0, info.windowWidth, info.windowHeight);
//        glClearBufferfv(GL_COLOR, 0, blue);
//        glClearBufferfv(GL_DEPTH, 0, &one);

//        glEnable (GL_BLEND);
//        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//        glBindTexture(GL_TEXTURE_2D, color_texture);

//        glUseProgram(program2);

//        glBindBuffer(GL_ARRAY_BUFFER, position_buffer);

//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), NULL);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
//        glEnableVertexAttribArray(1);


//        glUniformMatrix4fv(proj_location2, 1, GL_FALSE, proj_matrix);
//        glUniformMatrix4fv(mv_location2, 1, GL_FALSE, mv_matrix);

//        glDrawArrays(GL_TRIANGLES, 24, 6);

//        glBindTexture(GL_TEXTURE_2D, 0);
//    }

//    virtual void shutdown()
//    {
//        glDeleteVertexArrays(1, &vao);
//        glDeleteProgram(program1);
//        glDeleteProgram(program2);
//        glDeleteBuffers(1, &position_buffer);
//        glDeleteFramebuffers(1, &fbo);
//        glDeleteTextures(1, &color_texture);
//    }

//private:
//    GLuint          program1;
//    GLuint          program2;
//    GLuint          vao;
//    GLuint          position_buffer;
//    GLuint          position_buffer2;
//    GLuint          index_buffer;
//    GLuint          fbo;
//    GLuint          color_texture;
//    GLuint          depth_texture;
//    GLint           mv_location;
//    GLint           proj_location;
//    GLuint          mv_location2;
//    GLuint          proj_location2;
//};

//DECLARE_MAIN(basicfbo_app)





