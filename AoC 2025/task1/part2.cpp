#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "task 1 part 2 start" << endl;

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
		
		if (value == 0)
		{
			continue;
		}

		if (direction == 'L')
		{
			for (int i = 0; i < value; i++)
			{
				current_value -= 1;
				if (current_value == 0)
				{
					zero_cnt++;
				}
				if (current_value < 0)
				{
					current_value += 100;
				}
			}		
		}
		else if (direction == 'R')
		{
			for (int i = 0; i < value; i++)
			{
				current_value += 1;
				if (current_value == 100)
				{
					zero_cnt++;
					current_value -= 100;
				}
			}		
		}
		
	}

	file.close();
	cout << zero_cnt << endl;

	// 7408

	return 0;
}