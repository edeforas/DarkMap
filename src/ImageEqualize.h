#ifndef ImageEqualize_
#define ImageEqualize_

#include "ImageTransform.h"

class ImageEqualize: public ImageTransform
{
public:
	ImageEqualize();
	virtual ~ImageEqualize();

	virtual void compute(const cv::Mat & mIn,cv::Mat & mOut);
	
};

#endif
