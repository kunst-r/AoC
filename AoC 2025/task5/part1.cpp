#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
std::vector<string> ranges;
int fresh_ingredients = 0;

int main()
{
	cout << "task 4 part 1 \n";

	ifstream file("input.txt");
	string line;
	while (getline(file, line))
	{
		if (line.find('-') != string::npos)
		{
			ranges.push_back(line);
		}
		else if (line == "")
		{
			// empty line separator
		}
		else
		{
			unsigned long long product_id = stoull(line);
			
			for (auto r : ranges)
			{
				unsigned long long range_start = stoull(r.substr(0, r.find('-')));
				unsigned long long range_end = stoull(r.substr(r.find('-') + 1));
				if (product_id >= range_start && product_id <= range_end)
				{
					fresh_ingredients++;
					break;
				}
			}
		}
	}

	/*
	for (auto r : ranges)
	{
		cout << "range start = " << r.substr(0, r.find('-')) << ", range end = " << r.substr(r.find('-') + 1) << "\n";
	}
	*/

	cout << "fresh ingredients: " << fresh_ingredients << "\n";

	return 0;
}