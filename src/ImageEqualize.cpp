#include "ImageEqualize.h"	
//////////////////////////////////////////////////////////////////////////////
ImageEqualize::ImageEqualize()
{ }
//////////////////////////////////////////////////////////////////////////////
ImageEqualize::~ImageEqualize()
{ }
//////////////////////////////////////////////////////////////////////////////
void ImageEqualize::compute(const cv::Mat & mIn,cv::Mat & mOut)
{
    cv::equalizeHist(mIn, mOut);
}
//////////////////////////////////////////////////////////////////////////////
