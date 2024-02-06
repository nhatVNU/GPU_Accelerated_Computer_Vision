#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaarithm.hpp>
#include <iostream>
#include <opencv2/cudaimgproc.hpp>

int main()
{
    cv::Mat h_img = cv::imread("dataset/cameraman.tif", 0);
    cv::cuda::GpuMat d_img, d_result;
    d_img.upload(h_img);

    cv::cuda::equalizeHist(d_img, d_result);
    cv::Mat h_result;
    d_result.download(h_result);
    cv::imshow("Original Image", h_img);
    cv::imshow("Histogram Equalized Image", h_result);
    cv::waitKey();
    return 0;
}
