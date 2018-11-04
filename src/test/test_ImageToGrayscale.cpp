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

    windowColor.open("ImageColor");
    windowGrey.open("ImageGrey");

    if(!camera.open())
    {
        cout << "unable to open camera!" << endl;
        return -1;
    }

    cv::Mat m,mGrey;
	
    for(int i=0;i<300;i++)
    {
        camera.get(m);
        im2gray.compute(m,mGrey);
        windowColor.set(m);
        windowGrey.set(mGrey);
    }

    return 0;
}
