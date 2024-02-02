#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS     10000
#define SIZE            10
#define BLOCK_WIDTH     100

__global__ void gpu_increment_without_atomic(int *d_in)
{
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    tid = tid % SIZE;
    //d_in[tid] += 1;
    atomicAdd(&d_in[tid], 1);
}

int main() 
{
    printf("%d total threads in %d blocks writing into %d array elements\n", NUM_THREADS, NUM_THREADS / BLOCK_WIDTH, SIZE);

    int h_in[SIZE];
    const int ARRAY_BYTES = SIZE * sizeof(int);
    int* d_in;
    cudaMalloc((void**)&d_in, ARRAY_BYTES);

    cudaMemset((void*)d_in, 0, ARRAY_BYTES);
    gpu_increment_without_atomic << <NUM_THREADS / BLOCK_WIDTH, BLOCK_WIDTH >> > (d_in);
    cudaMemcpy(h_in, d_in, ARRAY_BYTES, cudaMemcpyDeviceToHost);

    printf("Number of times a particular Array index has been incremented without atomic add is: \n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("index: %d --> %d times\n ", i, h_in[i]);
    }
    cudaFree(d_in);
    return 0;
}