#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaarithm.hpp>
#include <iostream>

int main() 
{
    /* Read two images */
    cv::Mat h_img1 = cv::imread("dataset/cameraman.tif");
    cv::Mat h_img2 = cv::imread("dataset/test.jpg");
    /* Create memory for storing images on device */
    cv::cuda::GpuMat d_result, d_img1, d_img2;
    cv::Mat h_result;

    /* Upload image to GPU device */
    d_img1.upload(h_img1);
    d_img2.upload(h_img2);

    cv::cuda::subtract(d_img1, d_img2, d_result);

    /* Download result back to CPU host */
    d_result.download(h_result);

    cv::imshow("Image 1", h_img1);
    cv::imshow("Image 2", h_img2);
    cv::imshow("Result addition", h_result);
    cv::waitKey();

    return 0;
}
