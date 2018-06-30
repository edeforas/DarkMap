TEMPLATE = app
DESTDIR = ../DarkMap
QT += widgets

SOURCES += main.cpp \
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
