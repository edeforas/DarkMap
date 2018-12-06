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
		// update camera model, ( how to not reuse the same calibration file, a map?)
#if 0
		//Finds the camera intrinsic and extrinsic parameters from several views of a calibration pattern
		//cv::ArrayOfArrays toto;
		cv::InputArrayOfArrays objectsPoints;
		cv::InputArrayOfArrays imagePoints;
		cv::Size imageSize(m.raw().size());

		cv::Mat distCoeffs;
		cv::Mat rvecs;
		cv::Mat tvecs;

		
		double dRMS=cv::calibrateCamera(
			objectsPoints,
			imagePoints,
			imageSize,
			_cameraMatrix,
			 distCoeffs,
			 rvecs,
			 tvecs);
		
		/*,
			OutputArray stdDeviationsIntrinsics, 
			OutputArray stdDeviationsExtrinsics,
			OutputArray perViewErrors,
			int flags = 0,
			TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
		
			*/
			/*
			double 	cv::calibrateCamera(
				InputArrayOfArrays objectPoints, 
				InputArrayOfArrays imagePoints, 
				Size imageSize,
				InputOutputArray cameraMatrix,
				InputOutputArray distCoeffs, 
				OutputArrayOfArrays rvecs,
				OutputArrayOfArrays tvecs,
				int flags = 0, 
				TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
				*/
			//Returns
			//the overall RMS re - projection error.
#endif
	}

	// update image calibration, with camera model , if exist
	if(! _cameraMatrix.empty())
		m.set_camera_matrix(_cameraMatrix);
}
//////////////////////////////////////////////////////////////////////////////
