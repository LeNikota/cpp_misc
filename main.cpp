#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool isAllDigit(string value)
{
	for (char letter : value)
	{
		if (isdigit(letter) == 0)
		{
			return false;
		}
	}
	return true;
}

bool isOperator(char value)
{
	for (char letter : value)
	{
		if (isdigit(letter) == 0)
		{
			cout <<  << endl;
			return 0;
		}
	}
	return true;
}

int main()
{
	string x1, y1;
	int k;
	char oper;
	float x, y;
	bool isNumber;
	
	do
	{
		cout << "Input x\t";
		cin >> x1;
		isNumber = !isAllDigit(x1);
		if (isNumber)
		{
			system("CLS");
			cout << "Letters are not digits" << endl;
		}
	} while (isNumber);
	do
	{
		cout << "Input y\t";
		cin >> y1;
		isNumber = !isAllDigit(y1);
		if (isNumber)
		{
			system("CLS");
			cout << "Letters are not digits" << endl;
		}
	} while (isNumber);

	do
	{
		cout << "Input x\t";
		cin >> x1;
		isNumber = !isAllDigit(x1);
		if (isNumber)
		{
			system("CLS");
			cout << "Letters are not digits" << endl;
		}
	} while (isNumber);
	

	for (char letter : y1)
	{
		if (isdigit(letter) == 0)
		{
			cout << "ERROR" << endl;
			return 0;
		}
	}
	for (char o : {'+', '-', '*', '/'})
	{
		if (o == oper)
		{
			break;
		}
		else
			k++;
		if (k == 4)
		{
			cout << "ERROR" << endl;
			return 0;
		}
	}

	x = stof(x1);
	y = stof(y1);

	cout << x << oper << y << " = ";
	switch (oper)
	{
	case '+':
		cout << x + y;
		break;
	case '-':
		cout << x - y;
		break;
	case '*':
		cout << x * y;
		break;
	case '/':
	{
		if (y == 0)
			cout << "Error";
		else
			cout << x / y;
		break;
	}
	}
	//	cout << x << y << endl;
	//	cout<<x+y<<endl;
	//	cout<<x-y<<endl;
	//	cout<<x*y<<endl;
	//
	//
	return 0;
}