#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>
#include <time.h>

#define N   10

__global__ void gpu_shared_memory(float *d_in)
{
    int i;
    int index = threadIdx.x;
    float average;
    float sum = 0.0f;
    /* Defining shared memory */
    __shared__ float share_array[N];
    share_array[index] = d_in[index];

    /* This directive ensure all the writes to share memory have completed */
    __syncthreads();
    for (i = 0; i <= index; i++) {
        sum += share_array[i];
    }
    average = sum / (index + 1.0f);
    d_in[index] = average;
    share_array[index] = average;
}

int main() 
{
    float h_in[10];
    float* d_in;

    for (int i = 0; i < 10; i++) {
        h_in[i] = i;
    }

    cudaMalloc((void**)&d_in, 10 * sizeof(float));
    cudaMemcpy(d_in, h_in, 10 * sizeof(float), cudaMemcpyHostToDevice);
    gpu_shared_memory << <1, 10 >> > (d_in);
    cudaMemcpy(h_in, d_in, 10 * sizeof(float), cudaMemcpyDeviceToHost);
    printf("Use of shared memory on GPU: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("The running average after %d element is %f \n", i, h_in[i]);
    }
    return 0;
}