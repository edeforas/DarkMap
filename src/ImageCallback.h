#ifndef ImageCallback_
#define ImageCallback_

#include <string>
using namespace std;

#include "ImageTransform.h"

class ImageCallback: public ImageTransform
{
public:
	ImageCallback();
	virtual ~ImageCallback();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;

	//CvImage next_image();
	
protected:

private:
	
};

#endif
