//
//	Name:		Beauchamp, Joshua
//	Homework:	2
//	Due:		02-25-2025
//	Course:		cs-2560-01-sp25
//
//	Description:
//			The program is designed to roll two dice and output the results back to the user. The dice are rolled
//			a user-specified amount of times. Following the user input, the program calls a function getRandom
//			that returns a random number 1 to 6 for the dice values. Moreover, the random number is already
//			seeded in main, so that all the function does is calculate the random number to return. Once
//			the dice are rolled, they are compared to see if the two values have an associated roll name.
//			If not, the dice numbers are displayed following the roll count, where the roll count is outputted
//			every time.

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

// FUNCTION PROTOTYPE
// Returns a random number between the minimum and maximum number, or in
// this case a number between 1 and 6 for the number of faces on a dice
// The generator is already seeded from the main function
int getRandom(int min, int max);

// Prompts the user for an amount of times to roll two dice. It compares both values to see if they have
// an associated roll name with them. The roll values and, possibly, their name are displayed following
// the current roll count.
int main()
{
	srand(time(NULL));		// Seed for the random number generated
	int rollOne, rollTwo, userAmount;

	cout << "Craps Simulation by J. Beauchamp" << endl << endl;
	cout << "How many rolls? ";
	cin >> userAmount;
	cout << endl;

	// Loops the user specified amounts, rolling the two dice and comparing and outputting the results
	for(int i = 1; i <= userAmount; i++){
		rollOne = getRandom(1, 6);
		rollTwo = getRandom(1, 6);

		cout << setw(4) << i << ":" << "\t" << rollOne << " " << rollTwo << " ";

		if(rollOne == 1 && rollTwo == 1){	//Checks for Snake Eyes
			cout << "Snake Eyes" << endl;
		}
		else if (rollOne == 6 && rollTwo == 6){		//Checks for Boxcars
			cout << "Boxcars" << endl;
		}
		else if ((rollOne == 1 && rollTwo == 4) || (rollOne == 4 && rollTwo == 1)){		//Checks for Fever Fives
			cout << "Fever Fives" << endl;
		}
		else{
			cout << endl;
		}
	}
}

// FUNCTION DEFINITION
// Defined AFTER main
int getRandom(int min, int max){
	return rand() % ((max - min) + 1) + 1;
}