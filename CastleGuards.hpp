#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class CastleGuards
{
public:
	int missing(vector<string> castle)
	{
		int row = 0;
		for (int i = 0; i < castle.size(); i++)
		{
			int check = 0;
			for (int j = 0; j < castle[i].length(); j++)
				if (castle[i][j] == 'X')
					check = 1;
			if (check == 0)
				row++;
		}
		int col = 0;
		for (int i = 0; i < castle[0].length(); i++)
		{
			int check = 0;
			for (int j = 0; j < castle.size(); j++)
				if (castle[j][i] == 'X')
					check = 1;
			if (check == 0)
				col++;
		}
		if (row > col)
			return row;
		return col;
	}
};