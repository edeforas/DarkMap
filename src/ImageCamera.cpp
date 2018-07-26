#include "ImageCamera.h"	

ImageCamera::ImageCamera()
{ }
	
ImageCamera::~ImageCamera()
{}

bool ImageCamera::open(string sName)
{
    _vc.open(0);
    return true;
}

void ImageCamera::close()
{
}

bool ImageCamera::is_opened()
{
    return true;
}

void ImageCamera::run()
{
    _vc >> _m;
    forward(_m);
}
