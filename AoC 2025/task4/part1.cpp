#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define NUM_ROWS 138
#define NUM_COLS 138

int main()
{
	ifstream file("input.txt");
	string line;

	char mat[NUM_ROWS][NUM_COLS];

	int line_cnt = 0;
	while (getline(file, line))
	{
		// cout << "line = " << line << "\n";
		for (int j = 0; j < line.length(); j++)
		{
			char c = line[j];
			mat[line_cnt][j] = c;
		}
		line_cnt++;
	}

	/*
	for (int x = 0; x < NUM_ROWS; x++)
	{
		for (int y = 0; y < NUM_COLS; y++)
		{
			cout << mat[x][y];
		}
		cout << "\n";
	}
	*/

	int sum = 0;
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			if (mat[i][j] != '@') continue;
			int neighbor_roles = 0;
			if (i > 0 && j > 0 && mat[i-1][j-1] == '@') neighbor_roles++;
			if (i > 0 && mat[i-1][j] == '@') neighbor_roles++;
			if (i > 0 && j < (NUM_COLS - 1) && mat[i-1][j+1] == '@') neighbor_roles++;
			if (j > 0 && mat[i][j-1] == '@') neighbor_roles++;
			if (j < (NUM_COLS - 1) && mat[i][j+1] == '@') neighbor_roles++;
			if (i < (NUM_ROWS - 1) && j > 0 && mat[i+1][j-1] == '@') neighbor_roles++;
			if (i < (NUM_ROWS - 1) && mat[i+1][j] == '@') neighbor_roles++;
			if (i < (NUM_ROWS - 1) && j < (NUM_COLS - 1) && mat[i+1][j+1] == '@') neighbor_roles++;
			if (neighbor_roles < 4) 
			{
				// cout << "roll in mat[" << i << "][" << j << "] can be moved" << "\n";
				sum++;
			}
		}
	}

	cout << "sum = " << sum << "\n";

	return 0;
}