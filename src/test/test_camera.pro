TEMPLATE = app
DESTDIR = ../DarkMap

CONFIG(debug, debug|release):TARGET = test_camera_debug
CONFIG(release, debug|release):TARGET = test_camera

INCLUDEPATH += ..

#engine
SOURCES +=  \
        ../ImageProducer.cpp \
        ../ImageConsumer.cpp \
        ../ImageWindow.cpp \
        ../ImageCamera.cpp \
        test_camera.cpp
		
HEADERS += \
        ../ImageProducer.h \
        ../ImageConsumer.h \
        ../ImageWindow.h \
        ../ImageCamera.h \

#opencv 
INCLUDEPATH += $$(OPENCV_DIR)\include
CONFIG(debug, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world341d.lib
CONFIG(release, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world341.lib
