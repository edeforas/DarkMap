#include "ImageCalibration.h"
#include "ImageAnnotated.h"

#include <opencv2/calib3d.hpp>

//////////////////////////////////////////////////////////////////////////////
ImageCalibration::ImageCalibration()
{
	_bNewCalibration=false;
}
//////////////////////////////////////////////////////////////////////////////
ImageCalibration::~ImageCalibration()
{ }
//////////////////////////////////////////////////////////////////////////////
void ImageCalibration::update(ImageAnnotated & m)
{
	_bNewCalibration = false;

    if(m.has_checkerboard())
    {
		double dSquareSize = 30;  //mm
		int iNbCornersH = 9;
		int iNbCornersV = 6;

		// update camera model,
		std::vector<cv::Point3f> corners;
		std::vector<cv::Mat> allObjectsPoints;
		cv::Mat imagePoints=m.get_checkerboard_points();
		cv::Mat distCoefs;
		cv::Size imageSize(m.raw().size());
		cv::Mat rvecs;
		cv::Mat tvecs;

		int flags = cv::CALIB_FIX_ASPECT_RATIO;

		_imagePoints.push_back(imagePoints);

		if (_imagePoints.size() >= 5)
		{
			if (_imagePoints.size() > 10)
				_imagePoints.erase(_imagePoints.begin()); //erase oldest point

			//build the chessboard calibrations points
			for (int j = 0; j < iNbCornersV; j++)
				for (int i = 0; i < iNbCornersH; i++)
					corners.push_back(cv::Point3f((float)(j*dSquareSize), (float)(i*dSquareSize), 0.f));
			for (int i = 0; i < _imagePoints.size(); i++)
				allObjectsPoints.push_back(cv::Mat(corners)); // todo store in class member ?

			//if there is already a calibration, refine it
			if (!_cameraMatrix.empty())
				flags += cv::CALIB_USE_INTRINSIC_GUESS;

			double dRMS = cv::calibrateCamera(
				allObjectsPoints,
				_imagePoints,
				imageSize,
				_cameraMatrix,
				distCoefs,
				rvecs,
				tvecs,
				flags);

			if (dRMS != 0) //todo
				_bNewCalibration = true;

			//Returns the overall RMS reprojection error. TODO
			// todo select calibration matrix that gives lower RMS
		}
	}

	// update image calibration, with camera model, if exist
	if(! _cameraMatrix.empty())
		m.set_camera_matrix(_cameraMatrix);
}
//////////////////////////////////////////////////////////////////////////////
const cv::Mat& ImageCalibration::camera_matrix() const
{
	return _cameraMatrix;
}
//////////////////////////////////////////////////////////////////////////////
bool ImageCalibration::new_calibration() const
{
	return _bNewCalibration;
}
//////////////////////////////////////////////////////////////////////////////

#if 0
use?:
	/** @overload */
	CV_EXPORTS_W double calibrateCameraRO(InputArrayOfArrays objectPoints,
		InputArrayOfArrays imagePoints, Size imageSize, int iFixedPoint,
		InputOutputArray cameraMatrix, InputOutputArray distCoeffs,
		OutputArrayOfArrays rvecs, OutputArrayOfArrays tvecs,
		OutputArray newObjPoints,
		int flags = 0, TermCriteria criteria = TermCriteria(
			TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON));

#endif