#include <cstdlib>
#include <limits>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void clear_console()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

class File
{
private:
	string file_name;
	string prev_file_name;

public:
	File(string file_name)
	{
		this->file_name = file_name;
	};

	void read()
	{
		string text;
		ifstream file(file_name);

		while (getline(file, text))
		{
			cout << text << endl;
		}

		file.close();
	}

	void write()
	{
		string text;
		ofstream file(file_name, ios_base::app);

		while (true)
		{
			getline(cin, text);

			if (text == ":q")
				break;

			file << text << endl;
		}

		file.close();
	}

	bool check_exists(string file_name)
	{
		ifstream file(file_name);

		return file.good();
	}
};

int main()
{
	string file_name;
	char option;

	cout << "Enter the file name\t";
	cin >> file_name;
	clear_console();

	File file(file_name);
	while (true)
	{
		cout << file_name << " is opened" << endl;
		cout << "r - read, w - write, q - quit\t";
		cin >> option;
		clear_console();

		switch (option)
		{
		case 'r':
		{
			file.read();
			break;
		}
		case 'w':
		{
			file.write();
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