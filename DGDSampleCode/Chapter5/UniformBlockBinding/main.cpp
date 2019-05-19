

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
        static const char * vs_source[] =
        {
            "#version 450 core                                                                      \n"

            "layout (location=0) in vec3 position;                                                  \n"
            "layout (location=1) in vec3 color;                                                    \n"
            "layout(std140) uniform TransformBlock                                          \n"
            "{                                                                              \n"
            "   float scale;                                                                \n"
            "   vec3 translation;                                                           \n"
            "   float rotation[3];                                                          \n"
            "   mat4 projection_matrix;                                                     \n"
            "} transform;"
            "out vec3 vscolor;                                                                            \n"
            "void main(void)                                                                            \n"
            "{                                                                                          \n"
            //"   const vec4 points[3] = vec4[3](vec4(-0.25,-0.25,0.5,1.0),vec4(-0.25,0.25,0.5,1.0),  \n"
            //"                                   vec4(0.25,-0.25,0.5,1.0));                          \n"
            //"   vec3 ppp = vec3(1.0,1.0,1.0);                                                       \n"
            "       vec3 pp = position * transform.translation;                                            \n"
            //"   vec4 pos = vec4(position[0], position[1], position[2], 1.0);                        \n"
            "   vec4 pos = vec4(pp[0], pp[1], pp[2], 1.0);                        \n"
            "   gl_Position = pos;                                                             \n"
            "   vscolor = color;"
            "}                                                                                      \n"
        };


        static const char * fs_source[] =
        {
            "#version 450 core                          \n"
            "in vec3 vscolor;                           \n"
            "out vec4 color;                            \n"
            "layout (location =0) uniform vec4 vColorValue;                                 \n"

            "vec4 colorA = vec4(1.0, 0.0, 0.0, 1.0);    \n"
            "vec4 colorB = vec4(0.0, 0.0, 1.0, 1.0);    \n"
            "void main(void)                            \n"
            "{                                          \n"
             //"  color = mix(colorA, colorB, 0.5);       \n"
            //"       vec4 vfcolor = vec4(vscolor[0], vscolor[1], vscolor[2], 1.0);            \n"
            //"       color = vfcolor;                    \n"
            //"   color = vec4(1.0, 0.0, 0.0, 1.0);       \n"
        "       color = vColorValue;                        \n"
            "}                                          \n"
        };
        GLint isCompiled = -1;
        program = glCreateProgram();
        GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fs, 1, fs_source, NULL);
        glCompileShader(fs);
        glGetShaderiv(fs, GL_COMPILE_STATUS, &isCompiled);

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

        ///////////////////////
        static const GLfloat positions[] = {-0.25f, -0.25f, 0.5f,-0.25, 0.25, 0.5, 0.25,-0.25, 0.5};
        static const GLfloat colors[] = {1.0f,0.0f,0.0f, 0.0f,1.0f,0.0f, 0.0f,0.0f,1.0f};
        //use a buffer to send data to shader

        //set up a new buffer that will hold our positions values ie model coordinates
        glCreateVertexArrays(1, &vao);
        glCreateBuffers(2, &buffers[0]);//create 2 buffers buffers[0], [1]
        glBindVertexArray(vao);
        //fill in gpu memory with position coords
        glNamedBufferStorage(buffers[0], sizeof(positions),//1024 * 1024, //4 floats per point, 3 points in triangle
                            positions,
                             0
                             );

        //setup format of buffer[1] coords.
        glVertexArrayVertexBuffer(vao, 0, buffers[0], 0, sizeof(vmath::vec3));
        glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, 0);
        glVertexArrayAttribBinding(vao, 0,0);
         glEnableVertexArrayAttrib(vao, 0);

         //create buffer to hold colors defined above
         glNamedBufferStorage(buffers[1], sizeof(colors), colors, 0);
         //setup format of colors attribute so shader understands
         glVertexArrayVertexBuffer(vao, 1, buffers[1], 0, sizeof(vmath::vec3));
         glVertexArrayAttribFormat(vao, 1, 3, GL_FLOAT, GL_FALSE, 0);
         glVertexArrayAttribBinding(vao, 1, 1);
         glEnableVertexAttribArray(1);

         static const GLchar* uniformNames[4] =
         {
            "TransformBlock.scale",
             "TransformBlock.translation",
             "TransformBlock.rotation",
             "TransformBlock.projection_matrix"
         };


         //get indices of all uniform blocks in shader, in our case 1
         GLuint uniformIndices;//[4];
         glGetUniformIndices(program, 4, uniformNames, &uniformIndices);

         //these will hold values of strides and offsets of all vars in TransformBlock
         GLint uniformOffsets[4];
         GLint arrayStrides[4];
         GLint matrixStrides[4];
         //get strides/offsets etc of all vars in transformblock
         glGetActiveUniformsiv(program, 4, &uniformIndices,
                                GL_UNIFORM_OFFSET, uniformOffsets);
         glGetActiveUniformsiv(program, 4, &uniformIndices,
                                GL_UNIFORM_ARRAY_STRIDE, arrayStrides);
         glGetActiveUniformsiv(program, 4, &uniformIndices,
                                GL_UNIFORM_MATRIX_STRIDE, matrixStrides);
         std::cout<<"stop"<<std::endl;

         //create memory space for buffer to hold all uniform block vars
         unsigned char * buffer = (unsigned char*)malloc(4096);
         //fill in scale float scale;  TransformBlock.scale"
         *((float *)(buffer + uniformOffsets[0])) = 3.0f;

         //fill in TransformBlock.translation vec3 translation;
         ((float*)(buffer + uniformOffsets[1]))[0] = 0.5f;
         ((float*)(buffer + uniformOffsets[1]))[1] = 0.5f;
         ((float*)(buffer + uniformOffsets[1]))[2] = 1.0f;

         const GLfloat rotations[] = {30.0f, 40.0f, 60.0f};
         unsigned int offset = uniformOffsets[2];

         //set rotations in shader TransformBlock.rotation which is an float rotation[3]
         for(int n = 0 ; n < 3; n++)
         {
             *((float *)(buffer + offset)) = rotations[n];
             offset += arrayStrides[2];
         }
        const GLfloat matrix[] =
        {
            1.0f, 2.0f, 3.0f, 4.0f,
            9.0f, 8.0f, 7.0f, 6.0f,
            2.0f, 4.0f, 6.0f, 8.0f,
            1.0f, 3.0f, 5.0f, 7.0f
        };
        //set TransformBlock.projection_matrix mat4 projection_matrix;
        for(int i = 0 ;i <4 ; i++)
        {
            GLuint offset = uniformOffsets[3] + matrixStrides[3] *i;
            for(int j = 0 ; j < 4; j++)
            {
                *((float*)(buffer + offset)) = matrix[i*4+j];
                offset += sizeof(GLfloat);
            }
        }


        //buffer now holds the memory for TransformBlock that we want in gpu memory.
        GLuint buffer_b = 0;
        //get binding index of TransformBlock
        GLuint tbindex = glGetUniformBlockIndex(program, "TransformBlock");
        //set TransformBlock to binding index 0 which will match to our glBindBufferBase function below
        glUniformBlockBinding(program, tbindex, 0);

        //create a buffer that acts like common memory between cpu and gpu
        //
        glGenBuffers(1, &buffer_b);
        glBindBuffer(GL_UNIFORM_BUFFER, buffer_b);
        //fill buffer memory/cpu with values we set above ie copy over
        //buffer which we filled above to gpu memory
        glBufferData(GL_UNIFORM_BUFFER, 4096, buffer, GL_DYNAMIC_DRAW);
        //bind our buffer(buffer_b) to binding point 0? which is the uniform buffer in our
        //shader in the vertex shader
        glBindBufferBase(GL_UNIFORM_BUFFER, 0, buffer_b);

        //place to set breakpoint
        std::cout<<"testpoint"<<std::endl;
    }

    virtual void render(double currentTime)
    {
        static const GLfloat green[] = { 0.0f, 0.25f, 0.0f, 1.0f };

        glViewport(0, 0, info.windowWidth, info.windowHeight);
        glClearBufferfv(GL_COLOR, 0, green);

        glUseProgram(program);
        //bind position and color buffers so shader knows to use them
        glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
        glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);

        glUniform4f(0, 0.0f, 1.0f, 0.0f, 1.0f);
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





