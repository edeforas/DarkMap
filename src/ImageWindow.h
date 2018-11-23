#ifndef ImageWindow_
#define ImageWindow_

#include <string>
using namespace std;

#include "opencv2/imgproc.hpp"

class ImageWindow
{
public:
	ImageWindow();
	virtual ~ImageWindow();

    virtual bool open(string sName);
    virtual void close();
	virtual bool is_opened();
	
    virtual void set(const cv::Mat& m);

private:
    string _sName;
};

#endif
