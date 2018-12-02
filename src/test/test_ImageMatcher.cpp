#include "ImageCamera.h"
#include "ImageAnnotated.h"
#include "ImageCalibration.h"
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
	ImageCalibration calibration;
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
		calibration.update(annotated2);

		if (i<=10) //wait 10 frames for the camera to stabilize (focus,luminosity)
		{
			annotated1 = annotated2;
			continue;
		}
		
		if (annotated2.has_checkerboard())
			cout << "checkerboard!!" << std::endl;
		else
			cout << "no checkerboard." << std::endl;

		cout << "descriptors count: " << annotated2.keypoints().size() << endl;

		matcher.compute(annotated1, annotated2);

		drawMatches.compute(annotated1,annotated2, matcher.matches(), mOut);

		window.set(mOut);

		if (cv::waitKey(10) != -1)
			break;
	}

    return 0;
}
