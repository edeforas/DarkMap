TEMPLATE = app
DESTDIR = ../DarkMap

CONFIG(debug, debug|release):TARGET = test_ImageToGrayscale_debug
CONFIG(release, debug|release):TARGET = test_ImageToGrayscale

INCLUDEPATH += ..

#engine
SOURCES +=  \
        ../ImageProducer.cpp \
        ../ImageTransform.cpp \
        ../ImageConsumer.cpp \
        ../ImageWindow.cpp \
        ../ImageToGrayscale.cpp \
        ../ImageCamera.cpp \
        test_ImageToGrayscale.cpp
		
HEADERS += \
        ../ImageProducer.h \
        ../ImageTransform.h \
        ../ImageConsumer.h \
        ../ImageWindow.h \
        ../ImageToGrayscale.h \
        ../ImageCamera.h

#opencv 
INCLUDEPATH += $$(OPENCV_DIR)\include
CONFIG(debug, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world341d.lib
CONFIG(release, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world341.lib
