TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += ../../include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/aarch64-linux-gnu/release/ -lglfw
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/aarch64-linux-gnu/debug/ -lglfw
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/aarch64-linux-gnu/ -lglfw

INCLUDEPATH += $$PWD/../../../../../usr/lib/aarch64-linux-gnu
DEPENDPATH += $$PWD/../../../../../usr/lib/aarch64-linux-gnu

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/release/ -lsb7
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/debug/ -lsb7
else:unix: LIBS += -L$$PWD/../../../lib/ -lsb7

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/release/libsb7.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/debug/libsb7.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../lib/release/sb7.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../lib/debug/sb7.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../lib/libsb7.a

LIBS += -ldl -lGL
