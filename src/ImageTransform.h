#ifndef ImageTransform_
#define ImageTransform_

#include <string>
using namespace std;

#include "ImageProducer.h"
#include "ImageConsumer.h"

class ImageTransform: public ImageProducer, ImageConsumer
{
public:
	ImageTransform();
	virtual ~ImageTransform();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;

	//CvImage next_image();
	
protected:

private:
	
};

#endif
