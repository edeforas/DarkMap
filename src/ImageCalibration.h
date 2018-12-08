#ifndef ImageCalibration_
#define ImageCalibration_

#include "opencv2/imgproc.hpp"

class ImageAnnotated;

class ImageCalibration
{
public:
	ImageCalibration();
	virtual ~ImageCalibration();

	// update the calibration model with  this image if possible (checkerboard)
	// and then calibrate the image with the new or previous model, this is an input and output function
	void update(ImageAnnotated & m);

	const cv::Mat& camera_matrix() const;

	//return true if a new calibration occur
	bool new_calibration() const;

private:
	cv::Mat _cameraMatrix;
	std::vector<cv::Mat> _imagePoints;
	bool _bNewCalibration;
};

#endif
