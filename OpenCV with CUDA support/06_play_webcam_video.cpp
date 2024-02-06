#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace dnn;
using namespace std;

int main() 
{
    /* Open the webcam */
    VideoCapture cap(0);
    if (cap.isOpened() == false) {
        cout << "Cannot open webcam" << endl;
        return -1;
    }
    /* Get the frames rate of the video from webcam */
    double frames_per_second = cap.get(CAP_PROP_FPS);
    cout << "Frames per seconds: " << frames_per_second << endl;
    cout << "Press Q to quit" << endl;
    String win_name = "Webcam Video";
    namedWindow(win_name);
    while (1) {
        Mat frame;
        if (!cap.read(frame)) {
            break;
        }
        imshow(win_name, frame);
        if (waitKey(1) == 'q') {
            break;
        }
    }
    return 0;
}
