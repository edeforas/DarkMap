#include "ImageAnnotated.h"

#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
using namespace cv;
//////////////////////////////////////////////////////////////////////////////
ImageAnnotated::ImageAnnotated()
{
	_bHaveCheckerBoard = false;
}
//////////////////////////////////////////////////////////////////////////////
ImageAnnotated::~ImageAnnotated()
{ }
//////////////////////////////////////////////////////////////////////////////
void ImageAnnotated::compute(const cv::Mat & mRaw)
{
	//save raw image
	_mRaw = mRaw.clone();

	//Grayscale conversion if needed
	cv::Mat& mGreyR = _mRaw;
	cv::Mat mGrey;
	if (mGrey.channels() != 1)
	{
		cv::cvtColor(mRaw, mGrey, cv::COLOR_RGB2GRAY);
		mGreyR = mGrey;
	}

	//detect keypoints
	auto detector = cv::AKAZE::create(); //AKAZE, BRISK, ORB
	detector->detectAndCompute(mGreyR, cv::noArray(), _keypoints, _descriptors);
	if (_keypoints.size() > 500)
	{
		//detect checkerboard
		bool bCornersFound = cv::findChessboardCornersSB(mGreyR, cv::Size(9, 6), _chessboardCorners); //, CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE + CALIB_CB_FAST_CHECK);
		if (bCornersFound)
		{
		//todo	cv::cornerSubPix(mGreyR, _chessboardCorners, cv::Size(11, 11), cv::Size(-1, -1), cv::TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));
			//drawChessboardCorners(img, patternsize, Mat(corners), patternfound);
		// later, use findChessboardCornersSB()
		}
	}
	else
	{
		_chessboardCorners.resize(0, 0);
	}
}
//////////////////////////////////////////////////////////////////////////////	
const cv::Mat& ImageAnnotated::raw() const
{
	return _mRaw;
}
//////////////////////////////////////////////////////////////////////////////	
const std::vector<cv::KeyPoint>& ImageAnnotated::keypoints() const
{
	return _keypoints;
}
//////////////////////////////////////////////////////////////////////////////	
const cv::Mat& ImageAnnotated::descriptors() const
{
	return _descriptors;
}
//////////////////////////////////////////////////////////////////////////////	
bool ImageAnnotated::have_checkerboard() const
{
	return ! _chessboardCorners.empty();
}
//////////////////////////////////////////////////////////////////////////////	
bool ImageAnnotated::have_keypoints() const
{
	return _keypoints.size()!=0;
}
//////////////////////////////////////////////////////////////////////////////	
