#include "ImageWindow.h"	

#include "opencv2/highgui/highgui.hpp"

ImageWindow::ImageWindow()
{ }

ImageWindow::~ImageWindow()
{}

bool ImageWindow::open(string sName)
{
    _sName=sName;
    cv::namedWindow( sName, cv::WINDOW_AUTOSIZE | cv::WINDOW_KEEPRATIO );
    return true;
}

void ImageWindow::close()
{}

bool ImageWindow::is_opened()
{
    return false;
}

void ImageWindow::compute(const cv::Mat& m)
{
    cv::imshow(_sName, m );
    cv::waitKey(1); //need to add this, don't know why...
}


