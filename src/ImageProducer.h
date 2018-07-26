#ifndef ImageProducer_
#define ImageProducer_

#include <string>
using namespace std;

#include "opencv2/imgproc.hpp"

class ImageConsumer;

class ImageProducer
{
public:
	ImageProducer();
	virtual ~ImageProducer();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;
    virtual void run()=0;

    void add_consumer(ImageConsumer *pIC);
    void forward(const cv::Mat & m);

protected:

private:
    cv::Mat _img;
    ImageConsumer* _pConsumer;
};

#endif
