#include "ImageCamera.h"
#include "ImageToGrayscale.h"
#include "ImageEqualize.h"
#include "ImageWindow.h"

#include <iostream>
using namespace std;

int main()
{
    ImageCamera camera;
    ImageWindow windowColor, windowGreyEq;
    ImageToGrayscale im2gray;
    ImageEqualize imEq;

    if(!camera.open())
    {
        cout << "unable to open camera!" << endl;
        return -1;
    }

    windowColor.open("ImageColor");
    windowGreyEq.open("ImageGreyEqualized");

    cv::Mat m,mGrey,mGreyEq;
	
    for(int i=0;i<300;i++)
    {
        camera.get(m);
        windowColor.set(m);
        im2gray.compute(m,mGrey);
        imEq.compute(mGrey,mGreyEq);
        windowGreyEq.set(mGreyEq);
    }

    return 0;
}
