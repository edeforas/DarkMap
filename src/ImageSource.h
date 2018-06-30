#ifndef ImageSource_
#define ImageSource_

#include <string>
using namespace std;

class ImageSource
{
public:
	ImageSource();
	virtual ~ImageSource();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;

	//CvImage next_image();
	
protected:

private:
	
};

#endif
