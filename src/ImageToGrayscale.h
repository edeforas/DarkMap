#ifndef ImageToGrayscale_
#define ImageToGrayscale_

#include "opencv2/imgproc.hpp"

class ImageToGrayscale
{
public:
	ImageToGrayscale();
	virtual ~ImageToGrayscale();

    void compute(const cv::Mat & mIn,cv::Mat & mOut);
};

#endif
