#include "ImageProducer.h"	
#include "ImageConsumer.h"

ImageProducer::ImageProducer()
{
    _pConsumer=0;
}
	
ImageProducer::~ImageProducer()
{

}

void ImageProducer::add_consumer(ImageConsumer *pIC)
{
    _pConsumer=pIC;
}

void ImageProducer::forward(const cv::Mat & m)
{
    if(_pConsumer)
        _pConsumer->compute(m);
}
