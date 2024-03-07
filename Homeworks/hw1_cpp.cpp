#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 40;
/*
void sum(int* p, int n, int d[])
{
	*p = 0;
	for (int i = 0; i < n; ++i)
	{
		*p = *p + d[i];
	}
}
*/
/*
inline void sum(int& p, int n, int d[])
{
	p = 0;
	for (int i = 0; i < n; ++i)
	{
		p = p + d[i];
	}
}
*/
template <class summable>
// summable is a generic type
summable sum(int size, summable data[], summable p = 0)
{
	p = 0;
	for (int i = 0; i < size; ++i)
	{
		p = p + data[i];
	}

	return p;
}
int main(void)
{
	int n = 50;
	int accum = 0;
	vector<int> data(n);
	for (int i = 0; i < n; i++)
	{
		data[i] = i;
	}
	// see notes for data.data()
	accum = sum(n, data.data(), accum);
	cout << ("sum is %d\n", accum);
}
