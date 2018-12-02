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

	bool has_checkerboard()const;
	bool has_keypoints()const;
	
private:
    cv::Mat _mRaw;
	std::vector<cv::KeyPoint> _keypoints;
	cv::Mat _descriptors;
	cv::Mat _chessboardCorners;
	bool _bHaveCheckerBoard;

};

#endif
