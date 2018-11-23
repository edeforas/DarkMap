#ifndef ImageMatcher_
#define ImageMatcher_

#include "opencv2/features2d.hpp"
using namespace cv;

#include "ImageAnnotated.h"

class ImageMatcher
{
public:
	ImageMatcher();
	virtual ~ImageMatcher();

	void compute(const ImageAnnotated& im1, const ImageAnnotated& im2);
	
	const cv::Mat & fundamental_matrix() const;

private:
	Ptr<BFMatcher> _matcher;
	cv::Mat _mFundamental;

	std::vector<DMatch> _matches; //debug purpose

};

#endif
