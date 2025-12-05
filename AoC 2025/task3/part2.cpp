#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;
int main()
{
    unsigned long long sum = 0;

    ifstream file("input.txt");
    string line;
    int previous_digit_index = -1;

    while (getline(file, line))
    {
        int digits[12] = {0};
        int indexes[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

        for (int i = 0; i < 12; i++)
        {
            // in looking for the 1st of 12 digits, we can only scan up to line.length() - 11
            // in looking for the 2nd of 12 digits, we can only scan from 1st digit index + 1 up to line.length() - 11
            // ...
            // in looking for the 11th of 12 digits, we can only scan from 10th digit index + 1 up to line.length() - 1
            // in looking for the 11th of 1 digits, we can only scan from 11th digit index + 1 up to line.length()

            for (int j = indexes[i] + 1; j < line.length() - (11 - i); j++)
            {
                char c = line[j];
                int digit = c - '0';
                
                
                if (digit > digits[i])
                {
                    digits[i] = digit;
                    indexes[i+1] = j;
                }
                
            }
        }

        unsigned long long joltage = 0;
        for (int i = 0; i < size(digits); i++)
        {
            joltage = joltage + pow(10, 11 - i) * digits[i];
        }
        sum += joltage;
    }
    file.close();

    cout << "joltage sum: " << sum << "\n";
    return 0;
}