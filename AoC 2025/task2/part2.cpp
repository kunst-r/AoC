#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout << "task 2 part 2" << endl;

	ifstream file("input.txt");
	if (!file.is_open())
	{
		cerr << "error when opening file input.txt" << endl;
		return 1;
	}

	unsigned long long sum = 0;
	string line;
	while (getline(file, line, ','))
	{
		// cout << "range: " << line << endl;
		size_t dash_index = line.find('-');
		unsigned long long a = stoull(line.substr(0, dash_index));
		unsigned long long b = stoull(line.substr(dash_index + 1));
		// cout << "a_str = " << a_str << ", ull a = " << a << endl;
		// cout << "b_str = " << b_str << ", ull b = " << b << endl;
		
		for (unsigned long long i = a; i <= b; i++)
		{
			string s = std::to_string(i);
			for (int j = 1; j <= s.length() / 2; j++)
			{
				// check if s.length() % j == 0
				if (s.length() % j != 0)
				{
					continue;
				}

				// if yes, repeat first j chars until you get a string same length as s
				string s_tmp = "";
				// cout << "s = " << s << ", j = " << j << endl;
				// cout << "j substring = " << s.substr(0, j) << endl;
				
				for (int k = 0; k < s.length() / j; k++)
				{
					s_tmp.append(s.substr(0, j));
				}
				
				// then, if that string and s are equal, that is new invalid ID - add it to the sum
				if (s.compare(s_tmp) == 0)
				{
					// cout << "invalid ID = " << s_tmp << endl;
					sum += i;
					break; // we don't want to add the same ID multiple times, e.g. 444444 would get added for 4-4-4-4-4-4, 44-44-44 and 444-444
				}
			}
		}
	}

	cout << "sum" << endl;
	cout << sum << endl;

	// 34459250159 - too high
	// 20942028255 - correct

	return 0;
}