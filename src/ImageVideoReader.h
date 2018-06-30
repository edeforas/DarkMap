#ifndef ImageVideoReader_
#define ImageVideoReader_

#include "ImageProducer.h"

class ImageVideoReader: public ImageProducer
{
public:
	ImageVideoReader();
	virtual ~ImageVideoReader();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;

	//CvImage next_image();
	
protected:

private:
	
};

#endif
