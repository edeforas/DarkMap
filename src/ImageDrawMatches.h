#ifndef ImageDrawMatches_
#define ImageDrawMatches_

#include "opencv2/features2d.hpp"
using namespace cv;

class ImageAnnotated;

class ImageDrawMatches
{
public:
	ImageDrawMatches();
	virtual ~ImageDrawMatches();
	
	void compute(const ImageAnnotated & ia1, const ImageAnnotated & ia2, std::vector<DMatch> matches, cv::Mat & mOut);
};

#endif
