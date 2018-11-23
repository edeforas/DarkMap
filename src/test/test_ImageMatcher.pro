TEMPLATE = app
DESTDIR = ../DarkMap

CONFIG(debug, debug|release):TARGET = test_ImageMatcher_debug
CONFIG(release, debug|release):TARGET = test_ImageMatcher

INCLUDEPATH += ..

#engine
SOURCES +=  \
        ../ImageProducer.cpp \
        ../ImageWindow.cpp \
        ../ImageToGrayscale.cpp \
        ../ImageEqualize.cpp \
        ../ImageCamera.cpp \
        test_ImageMatcher.cpp \
    ../ImageAnnotated.cpp \
    ../ImageMatcher.cpp \
    ../ImageDrawMatches.cpp
		
HEADERS += \
        ../ImageProducer.h \
        ../ImageWindow.h \
        ../ImageToGrayscale.h \
        ../ImageEqualize.h \
        ../ImageCamera.h \
    ../ImageAnnotated.h \
    ../ImageMatcher.h \
    ../ImageDrawMatches.h

#opencv 
INCLUDEPATH += $$(OPENCV_DIR)\include
CONFIG(debug, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world400d.lib
CONFIG(release, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world400.lib
