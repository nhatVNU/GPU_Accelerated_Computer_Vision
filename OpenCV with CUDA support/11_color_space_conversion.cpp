#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaarithm.hpp>
#include <iostream>
#include <opencv2/cudaimgproc.hpp>

int main() 
{
    cv::Mat h_img = cv::imread("dataset/test.jpg");
    cv::Mat h_result1, h_result2, h_result3, h_result4;
    cv::cuda::GpuMat d_img, d_result1, d_result2, d_result3, d_result4;

    /* Upload image to GPU device */
    d_img.upload(h_img);

    /* Convert image to different color spaces */
    cv::cuda::cvtColor(d_img, d_result1, cv::COLOR_BGR2GRAY);
    cv::cuda::cvtColor(d_img, d_result2, cv::COLOR_BGR2RGB);
    cv::cuda::cvtColor(d_img, d_result3, cv::COLOR_BGR2HSV);
    cv::cuda::cvtColor(d_img, d_result4, cv::COLOR_BGR2YCrCb);

    /* Download result back to CPU host */
    d_result1.download(h_result1);
    d_result2.download(h_result2);
    d_result3.download(h_result3);
    d_result4.download(h_result4);

    cv::imshow("Result in Gray", h_result1);
    cv::imshow("Result in RGB", h_result2);
    cv::imshow("Result in HSV", h_result3);
    cv::imshow("Result in YCrCb", h_result4);

    cv::waitKey();

    return 0;
}
