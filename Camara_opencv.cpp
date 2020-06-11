#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
    VideoCapture cap(0);

    if(!cap.isOpened())
        return -1;

    namedWindow("webcam");

    for(;;)
    {
        Mat frame;

        cap >> frame; 
        imshow("webcam", frame);

        int q = waitKey(10);

        if((char)q=='q') break;
    }
    return 0;
}
