#ifndef ImageTransform_
#define ImageTransform_

#include "opencv2/imgproc.hpp"

class ImageTransform
{
public:
	ImageTransform();
	virtual ~ImageTransform();

	virtual void compute(const cv::Mat & mIn,cv::Mat & mOut)=0;

protected:

private:
	
};

#endif
