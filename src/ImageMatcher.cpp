#include "ImageMatcher.h"	

#include "opencv2/calib3d.hpp"

////////////////////////////////////////////////////////////////////////////////
ImageMatcher::ImageMatcher()
{ 
	_matcher = cv::BFMatcher::create(NORM_HAMMING,true); // for ORB
}
////////////////////////////////////////////////////////////////////////////////
ImageMatcher::~ImageMatcher()
{ }
////////////////////////////////////////////////////////////////////////////////
void ImageMatcher::compute(const ImageAnnotated& im1, const ImageAnnotated& im2, std::vector< DMatch >& matches )
{	
	cv::Mat inliners;
	
	_matcher->match(im1.descriptors(), im2.descriptors(),matches);

	std::vector<cv::Point2f> vP1, vP2;
	cv::KeyPoint::convert(im1.keypoints(), vP1);
	cv::KeyPoint::convert(im2.keypoints(), vP2);

	_mFundamental=cv::findFundamentalMat(vP1,vP2, inliners, FM_RANSAC);







}
////////////////////////////////////////////////////////////////////////////////
const cv::Mat & ImageMatcher::fundamental_matrix() const
{
	return _mFundamental;
}
////////////////////////////////////////////////////////////////////////////////
