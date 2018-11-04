#ifndef ImageToGrayscale_
#define ImageToGrayscale_

#include "ImageTransform.h"

class ImageToGrayscale: public ImageTransform
{
public:
	ImageToGrayscale();
	virtual ~ImageToGrayscale();

	virtual void compute(const cv::Mat & mIn,cv::Mat & mOut);
};

#endif
