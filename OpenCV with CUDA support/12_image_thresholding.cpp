#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaarithm.hpp>
#include <iostream>
#include <opencv2/cudaimgproc.hpp>

int main() 
{
    cv::Mat h_img = cv::imread("dataset/cameraman.tif");
    cv::Mat h_result1, h_result2, h_result3, h_result4, h_result5;
    cv::cuda::GpuMat d_img, d_result1, d_result2, d_result3, d_result4, d_result5;

    /* Upload image to GPU device */
    d_img.upload(h_img);

    /* Convert image to different color spaces */
    cv::cuda::threshold(d_img, d_result1, 128.0, 255.0, cv::THRESH_BINARY);
    cv::cuda::threshold(d_img, d_result2, 128.0, 255.0, cv::THRESH_BINARY_INV);
    cv::cuda::threshold(d_img, d_result3, 128.0, 255.0, cv::THRESH_TRUNC);
    cv::cuda::threshold(d_img, d_result4, 128.0, 255.0, cv::THRESH_TOZERO);
    cv::cuda::threshold(d_img, d_result5, 128.0, 255.0, cv::THRESH_TOZERO_INV);

    /* Download result back to CPU host */
    d_result1.download(h_result1);
    d_result2.download(h_result2);
    d_result3.download(h_result3);
    d_result4.download(h_result4);
    d_result5.download(h_result5);
    
    cv::imshow("Originnal Img", h_img);
    cv::imshow("Threshhold binary", h_result1);
    cv::imshow("Threshhold binary inverse", h_result2);
    cv::imshow("Threshhold truncated", h_result3);
    cv::imshow("Threshhold truncated to zero", h_result4);
    cv::imshow("Threshhold truncated to zero inverse", h_result5);
    cv::waitKey();

    return 0;
}
