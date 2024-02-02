#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread("dataset/cameraman.tif");
	if (img.empty()) {
		cout << "Could not open an image" << endl;
		return -1;
	}

	String win_name = "My First Opencv Program";

	namedWindow(win_name);
	imshow(win_name, img);
	waitKey(0);
	destroyWindow(win_name);
	return 0;
}

