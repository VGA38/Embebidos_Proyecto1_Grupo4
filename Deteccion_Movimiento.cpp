#include <opencv2/opencv.hpp>
#include<iostream>
#include <opencv2/core/ocl.hpp>
#include <unistd.h>

using namespace cv;
using namespace std;
 
int main(int argc, char **argv) {

    Mat frame, gray, frameDelta1, thresh1, compFrame1;
    vector<vector<Point> > cnts;
    VideoCapture camera(0); //open camera
    
    camera.set(3, 512);
    camera.set(4, 288);

    sleep(3);
    camera.read(frame);

cvtColor(frame, compFrame1, COLOR_BGR2GRAY);
GaussianBlur(compFrame1, compFrame1, Size(21, 21), 0);

    while(camera.read(frame)) {

        cvtColor(frame, gray, COLOR_BGR2GRAY);
        GaussianBlur(gray, gray, Size(21, 21), 0);
  
        absdiff(compFrame1, frame, frameDelta1);
        threshold(frameDelta1, thresh1, 25, 255, THRESH_BINARY);
        dilate(thresh1, thresh1, Mat(), Point(-1,-1), 2);
        findContours(thresh1, cnts, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
       
         cvtColor(frame, compFrame1, COLOR_BGR2GRAY);
         GaussianBlur(compFrame1, compFrame1, Size(21,21),0); 
         

        for(int i = 0; i< cnts.size(); i++) {
            if(contourArea(cnts[i]) < 500) {
                continue;
            }

                putText(frame, "Motion Detected", Point(10, 20), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0,0,255),2);
                
                system("./intrusiones");   //Guarda el registro de la intrusion
        }
                
        imshow("Camera", frame);

        if(waitKey(1) == 27){
        break;
        }
    }
return 0;
}
