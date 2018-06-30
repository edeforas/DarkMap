TEMPLATE = app
DESTDIR = ../DarkMap
QT += widgets

INCLUDEPATH += ..

SOURCES += test_camera.cpp \
        ..\ImageProducer.cpp \
		..\ImageConsumer.cpp \
        ..\ImageWindow.cpp \
        ..\ImageCallback.cpp \
        ..\ImageVideoReader.cpp \
		..\ImageCamera.cpp
		
HEADERS += ..\ImageProducer.h \
        ..\ImageConsumer.h \
        ..\ImageWindow.h \
        ..\ImageCallback.h \
		..\ImageVideoReader.h \
		..\ImageCamera.h
