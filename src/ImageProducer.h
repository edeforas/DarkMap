#ifndef ImageProducer_
#define ImageProducer_

#include <string>
using namespace std;

#include "opencv2/imgproc.hpp"

class ImageProducer
{
public:
	ImageProducer();
	virtual ~ImageProducer();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;

	//CvImage next_image();
	
protected:

private:
    cv::Mat _img;
};

#endif
