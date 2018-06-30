TEMPLATE = app
DESTDIR = ../DarkMap
QT += widgets

SOURCES += main.cpp \
        ImageProducer.cpp \
		ImageConsumer.cpp \
        ImageDisplay.cpp \
        ImageVideoReader.cpp
		
HEADERS += ImageProducer.h \
        ImageConsumer.h \
        ImageDisplay.h \
		ImageVideoReader.h
