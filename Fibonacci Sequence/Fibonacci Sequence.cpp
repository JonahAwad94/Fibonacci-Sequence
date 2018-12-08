//////////////////////////////////////////////////////////////////////////////////////
// Quick Math program 1 - Fibonacci													//
// Created - 11/5/18 by Jonah Alexander												//
// Last Modified - 11/7/18 by Jonah Alexander										//
//																					//
// NOTES:																			//
// Can be done via recursion, but will be exponentially more resource intensive		//
// We are limiting the max input to 93 to avoid overflow on unsigned long long  int //
//  - This can be raised by using a user defined data type							//
//////////////////////////////////////////////////////////////////////////////////////
#include "pch.h" //For visual studio 2017
#include <iostream>

using namespace std;

const int fibListSize = 100;

unsigned long long int fib(int userInput);
void fibList(int userInput, unsigned long long int FibListValues[]);
void printList(unsigned long long int FibListValues[]);

int main()
{
	//Initiate array to hold FibList values
	unsigned long long int fibListValues[fibListSize];
	fibListValues[0] = 1;
	fibListValues[1] = 1;

	//MENU
	cout << "##################################\n"
		<< "# FIBONACCI SEQUENCE CALCULATOR  #\n"
		<< "# ------------------------------ #\n"
		<< "# 1. Find nth value              #\n"
		<< "# 2. List values up to nth value #\n"
		<< "# 3. Exit                        #\n"
		<< "##################################" << endl;
	int userChoice;
	cin >> userChoice;

	if (userChoice < 1 || userChoice > 3)
	{
		do {
			cout << "That is out of range, please select a number between 1 and 3." << endl;
			cin >> userChoice;
		} while (userChoice < 1 || userChoice > 3);
	}

	if (userChoice == 1) // Find nth value
	{
		int userInput;
		cout << "Enter n (Up to 93)." << endl;
		cin >> userInput;

		//Check Range
		if (userInput < 1 || userInput > 93)
		{
			do {
				cout << "That is out of range, please select a number between 1 and 93." << endl;
				cin >> userInput;
			} while (userInput <= 0 || userInput >= 93);
		}

		//Calulate Result
		unsigned long long int result = fib(userInput);


		//Print result
		// Scan last digit in number to use proper suffix (ie. 1st, 2nd, 3rd, Xth)
		cout << "\nThe " << userInput;
		if (userInput > 3 && userInput < 21)
			cout << "th ";
		else if (userInput % 10 == 1)
			cout << "st ";
		else if (userInput % 10 == 2)
			cout << "nd ";
		else if (userInput % 10 == 3)
			cout << "rd ";
		else
		{
			cout << "th ";
		}

		cout << "term of the fibonacci sequence is " << result << "." << endl << endl;


		//Repeat or Exit Program
		cout << "1. Go Back to Main Menu\n2. Exit" << endl;
		int userChoice2;
		cin >> userChoice2;

		if (userChoice2 == 1)
		{
			system("CLS");
			return main();
		}
		else
			return 0;
	}
	else if (userChoice == 2) // List all values up to nth value
	{
		int userInput;
		cout << "Enter a number to List fibonacci sequence to (Up to 93)." << endl;
		cin >> userInput;

		//Check Range
		if (userInput < 1 || userInput > 93)
		{
			do {
				cout << "That is out of range, please select a number between 1 and 93." << endl;
				cin >> userInput;
			} while (userInput <= 0 || userInput >= 93);
		}

		fibList(userInput, fibListValues);
		printList(fibListValues);

		//Repeat or Exit Program
		cout << "1. Go Back to Main Menu\n2. Exit" << endl;
		int userChoice2;
		cin >> userChoice2;

		if (userChoice2 == 1)
		{
			system("CLS");
			return main();
		}
		else
			return 0;
	}
	else
	{
		return 0; // Exit
	}

	return 0;
}

unsigned long long int fib(int userInput)
{
	// Test for base cases
	if (userInput == 1 || userInput == 2)
	{
		return 1;
	}

	unsigned long long int oneBefore = 1, twoBefore = 1;
	unsigned long long int result;

	//Calculate Fib value
	for (int i = 3; i <= userInput; i++)
	{
		result = oneBefore + twoBefore; //fib algorithm
		// Update previous values
		twoBefore = oneBefore;
		oneBefore = result;
	}

	return result;
}

void fibList(int userInput, unsigned long long int FibListValues[])
{
	// Test and print base cases
	if (userInput == 1)
		cout << "1" << endl;
	if (userInput == 2)
		cout << "1, 1" << endl;


	unsigned long long int oneBefore = 1, twoBefore = 1;
	unsigned long long int result;

	int i; //index counter
	//Calculate Fib value
	for (i = 3; i <= userInput; i++)
	{
		//fib algorithm, put result in fibListValues
		FibListValues[i - 1] = oneBefore + twoBefore;

		// Update previous values
		twoBefore = oneBefore;
		oneBefore = FibListValues[i - 1];
	}

	//"Cap Off" Array
	i++;
	FibListValues[i - 2] = 0;
}

void printList(unsigned long long int FibListValues[])
{
	//Format output
	cout << endl << "N\tValue" << endl;
	cout << "-\t-----" << endl;

	int i = 0, j = 1; //counters i for FibList index, j for N index
	while (FibListValues[i] != 0)
	{
		cout << j << ":\t" << FibListValues[i] << endl;
		i++; j++;
	}
	//format output
	cout << endl << endl;
}
