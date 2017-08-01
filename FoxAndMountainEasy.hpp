#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <stdlib.h> 
using namespace std;

class FoxAndMountainEasy
{
public:
	string possible(int n, int h0, int hn, string history)
	{
		int step_left = n - history.size();
		int curr_height = h0;
		for (int i = 0; i < history.size(); i++)
		{
			if (history[i] == 'D')
				curr_height--;
			else 
				curr_height++;
			if (curr_height < 0)
			{
				curr_height++;
				step_left--;
				if (step_left < 0)
					return "NO";
			}
		}
		if (abs(hn - curr_height) <= step_left)
			if (!((abs(hn - curr_height) % 2 == 0) and (step_left % 2 == 1)))
				if (!((abs(hn - curr_height) % 2 == 1) and (step_left % 2 == 0)))
				return "YES";
		return "NO";
	}
};