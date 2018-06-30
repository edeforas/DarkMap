#ifndef ImageConsumer_
#define ImageConsumer_

#include <string>
using namespace std;

class ImageConsumer
{
public:
	ImageConsumer();
	virtual ~ImageConsumer();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;

	//CvImage next_image();
	
protected:

private:
	
};

#endif
