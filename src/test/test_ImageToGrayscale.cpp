#include "ImageCamera.h"
#include "ImageWindow.h"
#include "ImageToGrayscale.h"

#include <iostream>
using namespace std;

int main()
{
    ImageCamera camera;
    ImageWindow window;
    ImageToGrayscale im2gray;
    window.open("Test");


    if(!camera.open())
    {
        cout << "unable to open camera!" << endl;
        return -1;
    }

    cv::Mat m;
    for(int i=0;i<300;i++)
    {
        camera.get(m);
        im2gray.compute(m,m);
        window.set(m);
    }

    return 0;
}
