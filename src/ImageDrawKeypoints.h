#ifndef ImageDrawKeypoints_
#define ImageDrawKeypoints_

#include "opencv2/features2d.hpp"
using namespace cv;

class ImageDrawKeypoints
{
public:
	ImageDrawKeypoints();
	virtual ~ImageDrawKeypoints();

    void compute(const cv::Mat & m, const std::vector<KeyPoint>& vKP, cv::Mat & mOut);
	
};

#endif
