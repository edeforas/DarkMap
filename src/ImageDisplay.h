#ifndef ImageDisplay_
#define ImageDisplay_

#include <string>
using namespace std;

#include "ImageConsumer.h"

class ImageDisplay: public ImageConsumer
{
public:
	ImageDisplay();
	virtual ~ImageDisplay();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;

	//CvImage next_image();
	
protected:

private:
	
};

#endif
