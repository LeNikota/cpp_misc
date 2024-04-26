// Origin https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
#include <iostream>
#include <cstdlib> // for exit
#include <limits>	 // for numeric_limits

using namespace std;

void ignoreLine()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getDouble()
{
	while (true) // Loop until user enters a valid input
	{
		cout << "Enter value: ";
		double x;
		cin >> x;

		// Check for failed extraction
		if (cin.fail()) // If the previous extraction failed
		{
			if (cin.eof()) // If the stream was closed
			{
				exit(0); // Shut down the program now
			}

			// Let's handle the failure
			cin.clear();	// Put us back in 'normal' operation mode
			ignoreLine(); // And remove the bad input

			cout << "Input is invalid.\n";
			continue;
		}

		ignoreLine(); // Remove any extraneous input
		return x;			// Return the value we extracted
	}
}

char getOperator()
{
	while (true) // Loop until user enters a valid input
	{
		cout << "Enter one of the following: +, -, *, or /: ";
		char operation{};
		cin >> operation;

		if (cin.fail()) // If the previous extraction failed
		{
			if (cin.eof()) // If the stream was closed
			{
				exit(0); // Shut down the program now
			}

			// Let's handle the failure
			cin.clear(); // put us back in 'normal' operation mode
		}

		ignoreLine(); // remove any extraneous input

		// Check whether the user entered meaningful input
		switch (operation)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			return operation; // Return the entered char to the caller
		default:						// Otherwise tell the user what went wrong
			cout << "Input is invalid.\n";
		}
	}
}

void printResult(double x, char operation, double y)
{
	switch (operation)
	{
	case '+':
		cout << x << " + " << y << " is " << x + y << '\n';
		break;
	case '-':
		cout << x << " - " << y << " is " << x - y << '\n';
		break;
	case '*':
		cout << x << " * " << y << " is " << x * y << '\n';
		break;
	case '/':
		cout << x << " / " << y << " is " << x / y << '\n';
		break;
	default:
		cout << "Something went wrong: printResult() got an invalid operator.\n";
	}
}

int main()
{
	double x = getDouble();
	char operation = getOperator();
	double y = getDouble();

	printResult(x, operation, y);

	return 0;
}