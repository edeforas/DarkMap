#ifndef ImageWindow_
#define ImageWindow_

#include <string>
using namespace std;

#include "ImageConsumer.h"

class ImageWindow: public ImageConsumer
{
public:
	ImageWindow();
	virtual ~ImageWindow();

    virtual bool open(string sName);
    virtual void close();
	virtual bool is_opened();
	
    virtual void compute(const cv::Mat& m);

protected:

private:
	
};

#endif
