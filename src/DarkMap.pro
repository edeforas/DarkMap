TEMPLATE = app
DESTDIR = ../DarkMap
QT += widgets

SOURCES += main.cpp \
        ImageProducer.cpp \
		ImageConsumer.cpp \
        ImageVideoReader.cpp
		
HEADERS += ImageProducer.h \
        ImageConsumer.h \
		ImageVideoReader.h
