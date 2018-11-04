#ifndef ImageCamera_
#define ImageCamera_

#include "opencv2/videoio/videoio.hpp"

#include "ImageProducer.h"

class ImageCamera: public ImageProducer
{
public:
	ImageCamera();
	virtual ~ImageCamera();

    virtual bool open(string sName="");
	virtual void close();
	virtual bool is_opened();
    virtual void get(cv::Mat& m);

private:
    cv::VideoCapture _vc;
};

#endif
