#include "ImageWindow.h"	

#include "opencv2/highgui/highgui.hpp"

ImageWindow::ImageWindow()
{ }

ImageWindow::~ImageWindow()
{}

bool ImageWindow::open(string sName)
{
    namedWindow( "Image", cv::WINDOW_AUTOSIZE );
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
    cv::imshow("Image", m );
    cv::updateWindow("Image");
}


