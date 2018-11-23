#ifndef ImageDrawMatches_
#define ImageDrawMatches_

#include "opencv2/features2d.hpp"
using namespace cv;

class ImageDrawMatches
{
public:
	ImageDrawMatches();
	virtual ~ImageDrawMatches();
	
	void compute(const cv::Mat & image1, const std::vector<KeyPoint> &vKP1, const cv::Mat & image2, const std::vector<KeyPoint> &vKP2, std::vector<DMatch> matches, cv::Mat & mOut);
};

#endif
