#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "task 1 part 1 start" << endl;

	ifstream file("input.txt");
	if (!file.is_open())
	{
		cerr << "Error opening file" << endl;
		return 1;
	}

	int current_value = 50; // starting value
	int zero_cnt = 0;
	string line;
	while (getline(file, line))
	{
		char direction = line.empty() ? '\0' : line[0];
		int value = stoi(line.substr(1));

		if (direction == 'L')
		{
			current_value = (current_value - value) % 100;
		}
		else // if (direction == 'R')
		{
			current_value = (current_value + value) % 100;
		}
		
		if (current_value == 0)
		{
			zero_cnt++;
		}
	}

	file.close();
	cout << zero_cnt << endl;

	return 0;
}