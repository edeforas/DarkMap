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
    virtual void run();
	
protected:

private:
    cv::VideoCapture _vc;
    cv::Mat _m;
};

#endif
