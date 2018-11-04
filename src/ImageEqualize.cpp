#include "ImageEqualize.h"	
#include "opencv2/imgproc.hpp"

ImageEqualize::ImageEqualize()
{ }

ImageEqualize::~ImageEqualize()
{ }

void ImageEqualize::compute(const cv::Mat & mIn,cv::Mat & mOut)
{
    cv::equalizeHist(mIn, mOut);
}
