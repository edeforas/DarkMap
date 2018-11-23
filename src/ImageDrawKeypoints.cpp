#include "ImageDrawKeypoints.h"	

ImageDrawKeypoints::ImageDrawKeypoints()
{ }

ImageDrawKeypoints::~ImageDrawKeypoints()
{ }

void ImageDrawKeypoints::compute(const cv::Mat & m, const std::vector<KeyPoint> &vKP, cv::Mat & mOut)
{
    cv::drawKeypoints(m,vKP,mOut);
}

	
