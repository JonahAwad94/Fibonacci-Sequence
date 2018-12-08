 // See "README.md"

#include "pch.h" //For visual studio 2017
#include <iostream>

using namespace std;

const int fibListSize = 100;

unsigned long long int fib(int userInput);
void fibList(int userInput, unsigned long long int FibListValues[]);
void printList(unsigned long long int FibListValues[]);
int getUserInput(int lowerBound, int upperBound);

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
	int userChoice = getUserInput(1, 3);

	if (userChoice == 1) // Find nth value
	{
		cout << "Enter a number to get nth value of Fibonacci Sequence. ";
		int userInput = getUserInput(1,93);

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
		int userChoice2 = getUserInput(1, 2);

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
		cout << "Enter a number to List fibonacci sequence to (Up to 93)." << endl;
		int userInput = getUserInput(1, 93);

		fibList(userInput, fibListValues);
		printList(fibListValues);

		//Repeat or Exit Program
		cout << "1. Go Back to Main Menu\n2. Exit" << endl;
		int userChoice2 = getUserInput(1, 2);

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

// Get user input, check if input is valid
int getUserInput(int lowerBound, int upperBound)
{
	int num;
	cin >> num;


	if (num < lowerBound || num > upperBound)
	{
		do
		{
			cout << "That is not a valid input, enter a number between " << lowerBound << " and " << upperBound <<". ";
			cin >> num;
		} while (num < lowerBound || num > upperBound);
	}

	return num;
}