#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

__global__ void square(float * d_out, float * d_in)
{
	int idx = threadIdx.x; // Thread Index within the block
	float f = d_in[idx];
	d_out[idx] = f * f;
}

int main(int argc, char ** argv) 
{
	const int ARRAY_SIZE = 96;
	const int ARRAY_BYTES = ARRAY_SIZE * sizeof(float);

	// generate the input array on the host
	float h_in[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) 
	{
		h_in[i] = float(i);
	}
	float h_out[ARRAY_SIZE];

	// declare GPU memory pointers
	float * d_in;
	float * d_out;

	// allocate GPU memory
	cudaMalloc((void**) &d_in, ARRAY_BYTES);
	cudaMalloc((void**) &d_out, ARRAY_BYTES);

	// transfer the array to the GPU
	cudaMemcpy(d_in, h_in, ARRAY_BYTES, cudaMemcpyHostToDevice);

	// launch the kernel
	square<<<1, ARRAY_SIZE>>>(d_out, d_in);
	// Syntax: Identifier<<<Blocks, Thread per block>>>(params...)
	// Thread Limit: 1024 per block (or 512 for older Nvidia GPUs)
	// Dimentionality using dim3(x,y,z)
	// Identifier<<<dim3(bx,by,bz),dim3(tx,ty,tz),shmem>>>(params...)

	// copy back the result array to the CPU
	cudaMemcpy(h_out, d_out, ARRAY_BYTES, cudaMemcpyDeviceToHost);

	// print out the resulting array
	for (int i =0; i < ARRAY_SIZE; i++) 
	{
		printf("%f\n", h_out[i]);
	}

	cudaFree(d_in);
	cudaFree(d_out);

	return 0;
}

