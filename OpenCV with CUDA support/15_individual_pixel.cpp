#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaarithm.hpp>
#include <iostream>
#include <opencv2/cudaimgproc.hpp>

int main()
{
    /* Gray scale image */
    cv::Mat h_img1 = cv::imread("dataset/cameraman.tif", 0);
    cv::Scalar intensity = h_img1.at<uchar>(cv::Point(20, 50));
    std::cout << "Pixel intensity of gray scale image at (20, 50) is: " << intensity << std::endl;
    
    /* Color image */
    cv::Mat h_img2 = cv::imread("dataset/test.jpg", 1);
    cv::Vec3b intensity1 = h_img2.at<cv::Vec3b>(cv::Point(20, 50));
    std::cout << "Pixel intensity of color image at (20, 50) is: " << intensity1 << std::endl;

    return 0;
}
