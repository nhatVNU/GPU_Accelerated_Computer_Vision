#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	/* Create blank black color Image with size 256 x 256 */
	Mat img(256, 256, CV_8UC1, Scalar(0));
	String win_name = "Blank image";
	namedWindow(win_name);
	imshow(win_name, img);
	waitKey(0);
	destroyWindow(win_name);
	return 0;
}