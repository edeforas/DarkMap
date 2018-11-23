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
    std::vector<DMatch> matches;
	bool bFirst = true;

	while(cv::waitKey(1)==-1)
    {
        camera.get(m);
        annotated2.compute(m);

		if (bFirst)
		{
            annotated1 = annotated2;
			bFirst = false;
		}

        matcher.compute(annotated1, annotated2, matches);

        drawMatches.compute(annotated1.raw(), annotated1.keypoints(), annotated2.raw(), annotated2.keypoints(), matches, mOut);

        window.set(mOut);
    }

    return 0;
}
