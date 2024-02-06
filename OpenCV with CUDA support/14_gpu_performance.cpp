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
    cv::cuda::GpuMat result_device1, result_device2, result_device3, result_device4, result_device5, img_device;

    /* Get initial time in miliseconds */

    img_device.upload(src);
    int64_t start_tick = cv::getTickCount();
    cv::cuda::threshold(img_device, result_device1, 128.0, 255.0, cv::THRESH_BINARY);
    cv::cuda::threshold(img_device, result_device2, 128.0, 255.0, cv::THRESH_BINARY_INV);
    cv::cuda::threshold(img_device, result_device3, 128.0, 255.0, cv::THRESH_TRUNC);
    cv::cuda::threshold(img_device, result_device4, 128.0, 255.0, cv::THRESH_TOZERO);
    cv::cuda::threshold(img_device, result_device5, 128.0, 255.0, cv::THRESH_TOZERO_INV);
    /* Get time after work has finished */
    int64_t delta = cv::getTickCount() - start_tick;

    result_device1.download(result_host1);
    result_device2.download(result_host2);
    result_device3.download(result_host3);
    result_device4.download(result_host4);
    result_device5.download(result_host5);



    /* Frequency of timer */
    double freq = cv::getTickFrequency();
    double work_fps = freq / delta;
    std::cout << "Performance of thresholding on CPU: " << std::endl;
    std::cout << "Time: " << (1 / work_fps) << std::endl;
    std::cout << "FPS: " << work_fps << std::endl;

    return 0;
}
