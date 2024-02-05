#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace dnn;
using namespace std;

int main() 
{
    /* Create blank blue color image with size 256 x 256 */
    Mat img(256, 256, CV_8UC3, Scalar(255, 0, 0));
    String win_name = "Blank blue color image";
    namedWindow(win_name);
    imshow(win_name, img);
    waitKey(0);
    destroyWindow(win_name);
    return 0;
}
