#ifndef ImageEqualize_
#define ImageEqualize_

#include "opencv2/imgproc.hpp"

class ImageEqualize
{
public:
	ImageEqualize();
	virtual ~ImageEqualize();

	void compute(const cv::Mat & mIn,cv::Mat & mOut);
	
};

#endif
