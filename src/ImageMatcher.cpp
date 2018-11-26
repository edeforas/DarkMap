#include "ImageMatcher.h"	

#include "opencv2/calib3d.hpp"

////////////////////////////////////////////////////////////////////////////////
ImageMatcher::ImageMatcher()
{ 
	_matcher = cv::BFMatcher::create(NORM_L2,true); // NORM_L2 , NORM_HAMMING
}
////////////////////////////////////////////////////////////////////////////////
ImageMatcher::~ImageMatcher()
{ }
////////////////////////////////////////////////////////////////////////////////
void ImageMatcher::compute(const ImageAnnotated& im1, const ImageAnnotated& im2 )
{	
	cv::Mat inliners;
	std::vector<cv::Point2f> vP1, vP2;
	std::vector<DMatch> localMatches;

	_matches.clear();
	if ((im1.descriptors().rows < 20) || (im2.descriptors().rows < 20))
		return;

	_matcher->match(im1.descriptors(), im2.descriptors(), localMatches);

	const auto & vKP1=im1.keypoints();
	const auto & vKP2=im2.keypoints();

	// use matches in order and fill vP1 and vP2 
	for (int i = 0; i < localMatches.size(); i++)
	{
		const DMatch& match = localMatches[i];

		// do not use the distance for now
		vP1.push_back(vKP1[match.queryIdx].pt);
		vP2.push_back(vKP2[match.trainIdx].pt);
	}

	//find the F matrix
	_mFundamental =cv::findFundamentalMat(vP1,vP2, inliners, FM_RANSAC);

	//keep only the good matches using inliners
	int iNbGoodMatches = 0;
	for (int i=0; i<inliners.rows; i++)
	{
		if (inliners.at<char>(i)!=0)
		{
			iNbGoodMatches++;
			_matches.push_back(localMatches[i]);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
const cv::Mat & ImageMatcher::fundamental_matrix() const
{
	return _mFundamental;
}
////////////////////////////////////////////////////////////////////////////////
const std::vector<DMatch> & ImageMatcher::matches() const
{
	return _matches;
}
////////////////////////////////////////////////////////////////////////////////
