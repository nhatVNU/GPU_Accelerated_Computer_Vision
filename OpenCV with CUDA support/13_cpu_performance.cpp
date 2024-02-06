#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaarithm.hpp>
#include <iostream>
#include <opencv2/cudaimgproc.hpp>

int main() 
{
    cv::Mat src = cv::imread("dataset/cameraman.tif", 0);
    cv::Mat result_host1, result_host2, result_host3, result_host4, result_host5;

    /* Get initial time in miliseconds */
    int64_t start_tick = cv::getTickCount();
    cv::threshold(src, result_host1, 128.0, 255.0, cv::THRESH_BINARY);
    cv::threshold(src, result_host2, 128.0, 255.0, cv::THRESH_BINARY_INV);
    cv::threshold(src, result_host3, 128.0, 255.0, cv::THRESH_TRUNC);
    cv::threshold(src, result_host4, 128.0, 255.0, cv::THRESH_TOZERO);
    cv::threshold(src, result_host5, 128.0, 255.0, cv::THRESH_TOZERO_INV);

    /* Get time after work has finished */
    int64_t delta = cv::getTickCount() - start_tick;

    /* Frequency of timer */
    double freq = cv::getTickFrequency();
    double work_fps = freq / delta;
    std::cout << "Performance of thresholding on CPU: " << std::endl;
    std::cout << "Time: " << (1 / work_fps) << std::endl;
    std::cout << "FPS: " << work_fps << std::endl;

    return 0;
}
