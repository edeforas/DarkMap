#ifndef ImageAnnotated_
#define ImageAnnotated_

#include "opencv2/features2d.hpp"

class ImageAnnotated
{
public:
	ImageAnnotated();
	virtual ~ImageAnnotated();

	void compute(const cv::Mat& mRaw);
	const cv::Mat& raw() const;
	
	const std::vector<cv::KeyPoint>& keypoints() const;
	const cv::Mat& descriptors() const;

	bool has_checkerboard() const; //do we have a checkerboard on the image?
	bool has_keypoints() const;
	bool is_calibrated() const; // is the image calibrated (undistorted)
	
	void set_camera_matrix(const cv::Mat& mCameraMatrix);

	const cv::Mat & get_checkerboard_points() const;

private:
    cv::Mat _mRaw;
	std::vector<cv::KeyPoint> _keypoints;
	cv::Mat _descriptors;
	cv::Mat _chessboardCorners;
	cv::Mat _cameraMatrix;
};

#endif
