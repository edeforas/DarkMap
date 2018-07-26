#include "ImageCamera.h"
#include "ImageWindow.h"

#include <iostream>
using namespace std;

int main()
{
    ImageCamera camera;
    ImageWindow window;

    camera.add_consumer(&window);

    if(!camera.open())
    {
        cout << "unable to open camera!" << endl;
        return -1;
    }

    for(int i=0;i<1000;i++)
        camera.run();

	return 0;
}
