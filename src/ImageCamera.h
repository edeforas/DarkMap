#ifndef ImageCamera_
#define ImageCamera_

#include "ImageProducer.h"

class ImageCamera: public ImageProducer
{
public:
	ImageCamera();
	virtual ~ImageCamera();

    virtual bool open(string sName="");
	virtual void close();
	virtual bool is_opened();

	//CvImage next_image();
	
protected:

private:
	
};

#endif
