TEMPLATE = app
CONFIG(debug, debug|release):TARGET = DarkMap_debug
CONFIG(release, debug|release):TARGET = DarkMap
QT += widgets core gui

win32:RC_FILE = DarkMap.rc
RESOURCES += DarkMap.qrc

#engine
SOURCES +=  \
        ImageProducer.cpp \
        ImageConsumer.cpp \
        ImageTransform.cpp \
        ImageWindow.cpp \
        ImageCallback.cpp \
        ImageVideoReader.cpp \
        ImageCamera.cpp \
    DialogOpen.cpp
		
HEADERS += \
		ImageProducer.h \
        ImageConsumer.h \
        ImageTransform.h \
        ImageWindow.h \
        ImageCallback.h \
        ImageCamera.h \
        ImageVideoReader.h \
    DialogOpen.h

#opencv 
INCLUDEPATH += $$(OPENCV_DIR)\include
CONFIG(debug, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world340d.lib
CONFIG(release, debug|release):LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world340.lib

#ui
SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui \
    DialogOpen.ui
