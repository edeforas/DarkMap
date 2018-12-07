#include "ImageCalibration.h"

#include "ImageAnnotated.h"

#include <opencv2/calib3d.hpp>
//////////////////////////////////////////////////////////////////////////////
ImageCalibration::ImageCalibration()
{ }
//////////////////////////////////////////////////////////////////////////////
ImageCalibration::~ImageCalibration()
{ }
//////////////////////////////////////////////////////////////////////////////
void ImageCalibration::update(ImageAnnotated & m)
{
    if(m.has_checkerboard())
    {
		// update camera model, (how to not reuse the same calibration file, a map?)
		//Finds the camera intrinsic and extrinsic parameters from several views of a calibration pattern

		cv::Mat objectsPoints; //todo
		cv::Mat imagePoints; //todo
		cv::Mat distCoefs;
		cv::Size imageSize(m.raw().size());
		cv::Mat rvecs;
		cv::Mat tvecs;
		int flags = cv::CALIB_FIX_ASPECT_RATIO+ cv::CALIB_USE_INTRINSIC_GUESS;

		//TODO

		double dRMS=cv::calibrateCamera(
			objectsPoints,
			imagePoints,
			imageSize,
			_cameraMatrix,
			distCoefs,
			rvecs,
			tvecs,
			flags);
		
			//Returns the overall RMS re - projection error.
	}

	// update image calibration, with camera model , if exist
	if(! _cameraMatrix.empty())
		m.set_camera_matrix(_cameraMatrix);
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

