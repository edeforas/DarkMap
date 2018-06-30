TEMPLATE = app
DESTDIR = ../DarkMap
QT += widgets

SOURCES += main.cpp \
        ImageProducer.cpp \
		ImageConsumer.cpp \
        ImageDisplay.cpp \
        ImageCallback.cpp \
        ImageVideoReader.cpp
		
HEADERS += ImageProducer.h \
        ImageConsumer.h \
        ImageDisplay.h \
        ImageCallback.h \
		ImageVideoReader.h
