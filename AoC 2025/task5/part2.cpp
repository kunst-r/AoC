#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
std::vector<string> fresh_id_ranges;
unsigned long long fresh_ingredients = 0;

int main()
{
	cout << "task 4 part 2 \n";

	ifstream file("input.txt");
	string line;
	while (getline(file, line))
	{
		if (line.find('-') != string::npos)
		{
			fresh_id_ranges.push_back(line);
		}
	}

	std::sort(fresh_id_ranges.begin(), fresh_id_ranges.end(), [](const string& a, const string& b)
	{
		unsigned long long start_a = stoull(a.substr(0, a.find('-')));
		unsigned long long start_b = stoull(b.substr(0, b.find('-')));
		return start_a < start_b;
	});

	for (const auto& r : fresh_id_ranges)
	{
		cout << r << "\n";
	}
	cout << "\n";

	bool has_merge_happened = false;
	do
	{
		has_merge_happened = false;
		int merge_index = -1;

		for (int i = 0; i < fresh_id_ranges.size() - 1; i++)
		{
			string a = fresh_id_ranges[i];
			unsigned long long start_a = stoull(a.substr(0, a.find('-')));
			unsigned long long end_a = stoull(a.substr(a.find('-') + 1));
			string b = fresh_id_ranges[i+1];
			unsigned long long start_b = stoull(b.substr(0, b.find('-')));
			unsigned long long end_b = stoull(b.substr(b.find('-') + 1));

			if (start_b <= end_a)
			{
				// merge
				cout << "MERGE" << "\n";
				cout << start_a << "-" << end_a << " + " << start_b << "-" << end_b << " = " << start_a << "-" << end_b << "\n";
				string new_range;
				if (end_b > end_a)
				{
					new_range = std::to_string(start_a) + "-" + std::to_string(end_b);
				}
				else
				{
					new_range = std::to_string(start_a) + "-" + std::to_string(end_a);
				}
				
				fresh_id_ranges[i+1] = new_range;
				merge_index = i;
				has_merge_happened = true;
				
				break;
			}
		}

		if (has_merge_happened)
		{
			fresh_id_ranges.erase(fresh_id_ranges.begin() + merge_index);
		}
	} while (has_merge_happened);
	
	for (auto r : fresh_id_ranges)
	{
		unsigned long long start_r = stoull(r.substr(0, r.find('-')));
		unsigned long long end_r = stoull(r.substr(r.find('-') + 1));
		fresh_ingredients += end_r - start_r + 1;
	}

	cout << "fresh ingredients: " << fresh_ingredients << "\n";

	return 0;
}