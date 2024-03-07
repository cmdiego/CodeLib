// pointer to int
void swap(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

// need new name bc NO OVERLOADING
void swap_double(double* i, double* j)
{
	double temp = *i;
	*i = *j;
	*j = temp;
}

int main()
{
	int a = 5;
	int b = 10;
	swap(&a, &b);
	
	return 0;
}