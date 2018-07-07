TEMPLATE = app
TARGET = DarkMap
QT += widgets core gui

win32:RC_FILE = DarkMap.rc
RESOURCES += DarkMap.qrc

SOURCES +=  \
        ImageProducer.cpp \
		ImageConsumer.cpp \
        ImageWindow.cpp \
        ImageCallback.cpp \
        ImageVideoReader.cpp \
		ImageCamera.cpp
		
HEADERS += ImageProducer.h \
        ImageConsumer.h \
        ImageWindow.h \
        ImageCallback.h \
        ImageCamera.h \
		ImageVideoReader.h

		
#opencv 
INCLUDEPATH += $$(OPENCV_DIR)\include
LIBS+=$$(OPENCV_DIR)\x64\vc15\lib\opencv_world340.lib
		
		
SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui
