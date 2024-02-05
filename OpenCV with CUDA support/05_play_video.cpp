#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

using namespace cv;
using namespace dnn;
using namespace std;

int main() 
{
    /* Open a video file from PC */
    String video_path = "dataset/men_sport.mp4";
    VideoCapture cap(video_path);
    if (!cap.isOpened()) {
        cout << "Cannot open the video file" << endl;
        return -1;
    }
    cout << "Press Q to quit" << endl;
    double frames_per_second = cap.get(CAP_PROP_FPS);
    cout << "Frames per seconds of the video is : " << frames_per_second;
    String win_name = "Video";
    namedWindow(win_name);
    while (1) {
        Mat frame;
        if(!cap.read(frame)){
            break;
        }
        imshow(win_name, frame);
        if (waitKey(frames_per_second) == 'q') break;
    }
    destroyWindow(win_name);
    return 0;
}
