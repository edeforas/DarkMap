TEMPLATE = app
DESTDIR = ../DarkMap
QT += widgets

CONFIG(debug, debug|release):TARGET = test_camera_debug
CONFIG(release, debug|release):TARGET = test_camera

INCLUDEPATH += ..

#engine
SOURCES +=  \
        ../ImageProducer.cpp \
        ../ImageConsumer.cpp \
        ../ImageTransform.cpp \
        ../ImageWindow.cpp \
        ../ImageCallback.cpp \
        ../ImageVideoReader.cpp \
        ../ImageCamera.cpp \
		test_camera.cpp
		
HEADERS += \
		../ImageProducer.h \
        ../ImageConsumer.h \
        ../ImageTransform.h \
        ../ImageWindow.h \
        ../ImageCallback.h \
        ../ImageCamera.h \
        ../ImageVideoReader.h

#opencv 
INCLUDEPATH += $$(OPENCV_DIR)\include
CONFIG(debug, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world340d.lib
CONFIG(release, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world340.lib