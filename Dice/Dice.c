/*
	Description:
	The following program computers the probability for dice possibilities.
	This files depict the C counterpart of the Dice_cpp file.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Preprocessor commands
// Note: We do note want to use preprocessor commands

#define SIDES 6
#define R_SIDE (rand() % SIDES + 1) // range: [1, 6]

#include <iostream>

int main()
{
	/*
		Monte Carlo Simulator
	*/
	int trials = 0;
	int d1, d2 = 0;
	const int n_dice = 2;
	int outcomes = {12};

	srand(clock()); // seed random number generator
	printf("\nEnter number of trials: ");
	scanf("%d", &trials);

	for (int j = 0; j < trials; ++j)
	{
		outcomes[(d1 = R_SIDE) + (d2 = R_SIDE)]++;
		printf("probability\n");
	}
	for (int j = 2; j < n_dice * SIDES + 1; ++j)
	{
		printf("j = %d p = %lf\n", j, (double)(outcomes[j] / trials));
	}
	
	return 0;
}


