#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaarithm.hpp>
#include <iostream>

int main() 
{
    cv::Mat h_img = cv::imread("dataset/cameraman.tif");
    cv::Mat h_result;
    cv::cuda::GpuMat d_img, d_result;

    /* Upload image to GPU device */
    d_img.upload(h_img);

    cv::cuda::bitwise_not(d_img, d_result);

    /* Download result back to CPU host */
    d_result.download(h_result);
    cv::imshow("Result invertion", h_result);
    cv::imwrite("dataset/cameraman_inversion.png", h_result);
    cv::waitKey();
    
    return 0;
}
