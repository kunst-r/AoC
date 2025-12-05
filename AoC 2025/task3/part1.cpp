#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    int sum = 0;

    ifstream file("input.txt");
    string line;
    while (getline(file, line))
    {
        // find the largest digit in all but the last place
        int tens_digit = -1;
        int tens_digit_index = -1;
        for (int i = 0; i < line.length() - 1; i++)
        {
            char c = line[i];
            int tmp = c - '0'; // remember ASCII
            if (tmp > tens_digit)
            {
                tens_digit = tmp;
                tens_digit_index = i;
            }

            // just to speed it up a little
            if (tens_digit == 9)
            {
                break;
            }
        }

        // find the biggest digit in all the places to the right of the tens_digit
        int ones_digit = -1;
        int ones_digit_index = -1;
        for (int i = tens_digit_index + 1; i < line.length(); i++)
        {
            char c = line[i];
            int tmp = c - '0';
            if (tmp > ones_digit)
            {
                ones_digit = tmp;
                ones_digit_index = i;
            }

            // just to speed it up a little
            if (ones_digit == 9)
            {
                break;
            }
        }

        int joltage = tens_digit * 10 + ones_digit;
        sum += joltage;
    }
    file.close();

    cout << "joltage sum: " << sum << "\n";
    return 0;
}