#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 4;

template<class printable>
printable print(const printable data[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << '\t';
	}
}


template<class T>
T sub(const T data[], int size, T s = 0)
{
	for (int i = 0; i < size; ++i)
	{
		s -= data[i];
	}

	return s;
}

template<class summable>
/*
	@brief: 
			'const' means NOT mutable
			paremeter 's' is a default parameter
*/
summable sum(const summable data[], int size, summable s = 0) // default value
{
	for (int i = 0; i < size; ++i)
	{
		s += data[i]; // Op: '+=' must work for whatever T is
	}

	return s;
}

//int main()
//{
//	int scores[] = {0, 1, 2, 3};
//	double d_scores[] = {0.0, 1.1, 2.2, 3.3};
//	vector<int> v_scores(N);
//
//	double result = 0;
//
//	// sum(scores, 92); // using default, position of argument matters
//	result = sum(d_scores, N); // not using default val
//}