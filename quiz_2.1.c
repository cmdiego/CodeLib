#include <stdlib.h>

#define N 4

void sum(double* accumulator, double* arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		accumulator = accumulator + arr[i];
	}
}

int main()
{
	double accum = 0;
	double arr[] = { 0, 1, 2, 3 };

	sum(&accum, arr, N);
	
	return 0;
}