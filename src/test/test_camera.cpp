#include "ImageCamera.h"
#include "ImageWindow.h"

#include <iostream>
using namespace std;

int main()
{
    ImageCamera camera;
    ImageWindow window;
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
        window.set(m);
    }

    return 0;
}
