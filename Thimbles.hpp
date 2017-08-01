#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Thimbles
{
public:
	int thimbleWithBall(vector<string> swaps)
	{
		char current = '1';
		for (int i = 0; i < swaps.size(); i++)
		{
			if (swaps[i][0] == current)
				current = swaps[i][2];
			else if (swaps[i][2] == current)
				current = swaps[i][0];
		}
		int result = (int)current - 48;
		return result;
	}
};