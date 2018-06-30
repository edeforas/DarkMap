#ifndef ImageSourceVideo_
#define ImageSourceVideo_

#include "ImageSource.h"

class ImageSourceVideo: public ImageSource
{
public:
	ImageSourceVideo();
	virtual ~ImageSourceVideo();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;

	//CvImage next_image();
	
protected:

private:
	
};

#endif
