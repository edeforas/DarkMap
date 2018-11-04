#include "ImageCamera.h"
#include "ImageToGrayscale.h"
#include "ImageWindow.h"

#include <iostream>
using namespace std;

int main()
{
    ImageCamera camera;
    ImageWindow windowColor, windowGrey;
    ImageToGrayscale im2gray;

    if(!camera.open())
    {
        cout << "unable to open camera!" << endl;
        return -1;
    }

    windowColor.open("ImageColor");
    windowGrey.open("ImageGrey");

    cv::Mat m,mGrey;
	
    for(int i=0;i<300;i++)
    {
        camera.get(m);
        windowColor.set(m);
        im2gray.compute(m,mGrey);
        windowGrey.set(mGrey);
    }

    return 0;
}
