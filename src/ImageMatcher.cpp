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
void ImageMatcher::compute(const ImageAnnotated& im1, const ImageAnnotated& im2 )
{	
	cv::Mat inliners;
	std::vector<cv::Point2f> vP1, vP2;
	std::vector<DMatch> matches;

	_matcher->match(im1.descriptors(), im2.descriptors(),matches);

	const auto & vKP1=im1.keypoints();
	const auto & vKP2 = im2.keypoints();

	// use matches in order and fill vP1 and vP2 
	for (int i = 0; i < matches.size(); i++)
	{
		const DMatch& match = matches[i];

		// do not use the distance for now
		vP1.push_back(vKP1[match.queryIdx].pt);
		vP2.push_back(vKP2[match.trainIdx].pt);
	}

	//find the F model
	_mFundamental =cv::findFundamentalMat(vP1,vP2, inliners, FM_RANSAC);

	//keep only the good matches using inliners
	_matches.clear();
	for (int i = 0; i < inliners.rows; i++)
	{
		if (inliners.at<char>(i))
		{
			_matches.push_back(DMatch()  )

		}
	}





	/*
	
	
Besides ratio test, you can:

Only use symmetric matches:

void symmetryTest(const std::vector<cv::DMatch> &matches1,const std::vector<cv::DMatch> &matches2,std::vector<cv::DMatch>& symMatches)
{
    symMatches.clear();
    for (vector<DMatch>::const_iterator matchIterator1= matches1.begin();matchIterator1!= matches1.end(); ++matchIterator1)
    {
        for (vector<DMatch>::const_iterator matchIterator2= matches2.begin();matchIterator2!= matches2.end();++matchIterator2)
        {
            if ((*matchIterator1).queryIdx ==(*matchIterator2).trainIdx &&(*matchIterator2).queryIdx ==(*matchIterator1).trainIdx)
            {
                symMatches.push_back(DMatch((*matchIterator1).queryIdx,(*matchIterator1).trainIdx,(*matchIterator1).distance));
                break;
            }
        }
    }
}
and since its a stereo image use ransac test:

void ransacTest(const std::vector<cv::DMatch> matches,const std::vector<cv::KeyPoint>&keypoints1,const std::vector<cv::KeyPoint>& keypoints2,std::vector<cv::DMatch>& goodMatches,double distance,double confidence,double minInlierRatio)
{
    goodMatches.clear();
    // Convert keypoints into Point2f
    std::vector<cv::Point2f> points1, points2;
    for (std::vector<cv::DMatch>::const_iterator it= matches.begin();it!= matches.end(); ++it)
    {
        // Get the position of left keypoints
        float x= keypoints1[it->queryIdx].pt.x;
        float y= keypoints1[it->queryIdx].pt.y;
        points1.push_back(cv::Point2f(x,y));
        // Get the position of right keypoints
        x= keypoints2[it->trainIdx].pt.x;
        y= keypoints2[it->trainIdx].pt.y;
        points2.push_back(cv::Point2f(x,y));
    }
    // Compute F matrix using RANSAC
    std::vector<uchar> inliers(points1.size(),0);
    cv::Mat fundemental= cv::findFundamentalMat(cv::Mat(points1),cv::Mat(points2),inliers,CV_FM_RANSAC,distance,confidence); // confidence probability
    // extract the surviving (inliers) matches
    std::vector<uchar>::const_iterator
    itIn= inliers.begin();
    std::vector<cv::DMatch>::const_iterator
    itM= matches.begin();
    // for all matches
    for ( ;itIn!= inliers.end(); ++itIn, ++itM)
    {
        if (*itIn)
        { // it is a valid match
            goodMatches.push_back(*itM);
        }
    }
}
	*/

}
////////////////////////////////////////////////////////////////////////////////
const cv::Mat & ImageMatcher::fundamental_matrix() const
{
	return _mFundamental;
}
////////////////////////////////////////////////////////////////////////////////
