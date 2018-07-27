#include "ImageCamera.h"
#include "ImageWindow.h"

#include <iostream>
using namespace std;

int main()
{
    ImageCamera camera;
    ImageWindow window;
    window.open("Test");

    camera.add_consumer(&window);

    if(!camera.open())
    {
        cout << "unable to open camera!" << endl;
        return -1;
    }

    for(int i=0;i<300;i++)
        camera.run();

	return 0;
}
