#include "ImageAnnotated.h"

#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
using namespace cv;
//////////////////////////////////////////////////////////////////////////////
ImageAnnotated::ImageAnnotated()
{ }
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
		if (!bCornersFound)
		{ 	
			_chessboardCorners.resize(0, 0);
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
bool ImageAnnotated::has_checkerboard() const
{
	return ! _chessboardCorners.empty();
}
//////////////////////////////////////////////////////////////////////////////	
bool ImageAnnotated::has_keypoints() const
{
	return _keypoints.size()!=0;
}
//////////////////////////////////////////////////////////////////////////////	
bool ImageAnnotated::is_calibrated() const
{
	return !_cameraMatrix.empty();
}
//////////////////////////////////////////////////////////////////////////////
void ImageAnnotated::set_camera_matrix(const cv::Mat & mCameraMatrix)
{
	_cameraMatrix = mCameraMatrix;
}
//////////////////////////////////////////////////////////////////////////////
const cv::Mat & ImageAnnotated::get_checkerboard_points() const
{
	return _chessboardCorners;
}
//////////////////////////////////////////////////////////////////////////////	
