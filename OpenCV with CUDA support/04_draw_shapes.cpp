#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace dnn;
using namespace std;

int main() 
{
    /* Create blank blue color image with size 256 x 256 */
    Mat img(512, 512, CV_8UC3, Scalar(0, 0, 0));
    line(img, Point(0, 0), Point(200, 300), Scalar(0, 0, 255), 2);
    rectangle(img, Point(100, 200), Point(400, 300), Scalar(0, 255, 0), 1); 
    circle(img, Point(400, 400), 50, Scalar(0, 255, 255), 2);
    ellipse(img, Point(256, 256), Point(100, 200), 0, 0, 270, Scalar(0, 0, 255), -1);
    String win_name = "Blank blue color image";
    namedWindow(win_name);
    imshow(win_name, img);
    waitKey(0);
    destroyWindow(win_name);
    return 0;
}
