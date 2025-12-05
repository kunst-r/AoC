#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout << "task 2 part 1" << endl;

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
			if (s.length() % 2 != 0)
			{
				continue;
			}

			string h1 = s.substr(0, s.length() / 2);
			string h2 = s.substr(s.length() / 2);
			// cout << "s = " << s << ", h1 = " << h1 << ", h2 = " << h2 << endl;
			if (h1.compare(h2) == 0)
			{
				sum += i;
			}
		}
	}

	cout << "sum" << endl;
	cout << sum << endl;
	

	return 0;
}