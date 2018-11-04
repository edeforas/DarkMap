#include "ImageToGrayscale.h"	
#include "opencv2/imgproc.hpp"

ImageToGrayscale::ImageToGrayscale()
{ }

ImageToGrayscale::~ImageToGrayscale()
{ }

void ImageToGrayscale::compute(const cv::Mat & mIn,cv::Mat & mOut)
{
    if(mIn.channels()!=1)
        cvtColor(mIn, mOut, cv::COLOR_RGB2GRAY);
    else
        mOut=mIn;
}
