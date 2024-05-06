#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void read(string file_name)
{
	string text;
	ifstream file(file_name);

	while (getline(file, text))
	{
		cout << text << endl;
	}

	file.close();
}

void write(string file_name)
{
	string text;
	ofstream file(file_name, ios_base::app);
	while (true)
	{
		getline(cin, text);

		if (text == ":q")
		{
			file.close();
			return;
		}

		file << text << endl;
	}
}

int main()
{
	char option;
	string file_name;

	cout << "\nEnter the file name\t";
	cin >> file_name;

	while (true)
	{
		cout << "\nr - read, w - write, everything else - quit\t";
		cin >> option;

		switch (option)
		{
		case 'r':
		{
			read(file_name);
			break;
		}
		case 'w':
		{
			write(file_name);
			break;
		}
		default:
		{
			return 0;
		}
		}
	}

	return 0;
}