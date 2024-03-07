/*
	Monte Carlo Simulation:
	The Monte Carlo simulation is a probabilistic model that can include an element of uncertainty or randomness in its prediction. 
	When you use a probabilistic model to simulate an outcome, you will get different results each time. 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Preprocessor commands
// Note: We do note want to use preprocessor commands

const int sides = 6;

// Keyword: inline	-	Request the compiler to inline the function body.
//						Inline functions are normally defined in header files.
//						It's a replacement for code macros '#define'
//			
//			scope res op	-	Allows the use of multiple libraries from different namespaces

inline int r_sides() { return (rand() % sides + 1); }

int main(void)
{
	int trials = 0;
	int d1, d2 = 0;
	const int n_dice = 2;

	srand(clock()); // initializing seed random number generator
	cout << "\nEnter number of trials:W"; // prefix 'std::' scope res op 
	cin >> trials; // compare to scanf

	int* outcomes = new int[n_dice * sides + 1];

	for (int j = 0; j < trials; ++j)
	{
		outcomes[(d1 = r_sides()) + (d2 = r_sides())]++; //warning: uninitialized memory 
		cout << ("probability\n");
	}
	for (int j = 2; j < n_dice * sides + 1; ++j)
	{	
		// safe casting in C // (double)exp
		// in C: cout << ("j = %d p = %lf\n", j, (double)(outcomes[j] / trials));
		cout << "j = " << j << " p = "
			// safe casting in C++
			<< static_cast<double>(outcomes[j] / trials)
			<< endl; // io manipulator, cmd for iostream
	}

	return 0;
}
