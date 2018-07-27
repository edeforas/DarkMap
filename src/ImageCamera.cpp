#include "ImageCamera.h"	

ImageCamera::ImageCamera()
{ }
	
ImageCamera::~ImageCamera()
{}

bool ImageCamera::open(string sName)
{
    return _vc.open(0);
}

void ImageCamera::close()
{
    _vc.release();
}

bool ImageCamera::is_opened()
{
    return _vc.isOpened();
}

void ImageCamera::run()
{
    _vc >> _m;
    forward(_m);
}
