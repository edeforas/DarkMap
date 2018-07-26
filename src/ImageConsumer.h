#ifndef ImageConsumer_
#define ImageConsumer_

#include <string>
using namespace std;

#include "opencv2/core/mat.hpp"

class ImageConsumer
{
public:
	ImageConsumer();
	virtual ~ImageConsumer();

    virtual bool open(string sName) =0;
	virtual void close() =0;
	virtual bool is_opened() =0;
	
    virtual void compute(const cv::Mat& m)=0;

protected:

private:
	
};

#endif
