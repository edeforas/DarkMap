#include "ImageCamera.h"
#include "ImageAnnotated.h"
#include "ImageMatcher.h"
#include "ImageDrawMatches.h"
#include "ImageWindow.h"

#include "opencv2/highgui.hpp"

#include <iostream>
using namespace std;

int main()
{
    ImageCamera camera;
    ImageAnnotated annotated1, annotated2;
	ImageMatcher matcher;

    ImageDrawMatches drawMatches;
    ImageWindow window;

    if(!camera.open())
    {
        cout << "unable to open camera!" << endl;
        return -1; 
    }

    window.open("Images and match lines, key to exit");

	cv::Mat m,mOut; 
	
	for (int i = 0; i < 10000; i++)
	{
		camera.get(m);
		annotated2.compute(m);

		if (i<=20) //wait 20 frames for the camera to converge (focus,luminosity)
		{
			annotated1 = annotated2;
			continue;
		}

		matcher.compute(annotated1, annotated2);

		drawMatches.compute(annotated1.raw(), annotated1.keypoints(), annotated2.raw(), annotated2.keypoints(), matcher.matches(), mOut);

		window.set(mOut);

		if (cv::waitKey(1) != -1)
			break;
	}

    return 0;
}
