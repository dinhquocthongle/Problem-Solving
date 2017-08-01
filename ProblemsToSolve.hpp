#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <stdlib.h> 
using namespace std;

class ProblemsToSolve
{
public:
	int minNumber(vector<int> pleasantness, int variety)
	{
		int result = 1000000;
		int check = 0;
		vector<vector<int> > diff(pleasantness.size(),vector<int>(pleasantness.size()));
		for (int i = 0; i < pleasantness.size(); i++)
			for (int j = 0; j < pleasantness.size(); j++)
				diff[i][j] = abs(pleasantness[i]-pleasantness[j]);
		for (int i = 0; i < pleasantness.size(); i++)
			for (int j = i+1; j < pleasantness.size(); j++)
				if (diff[i][j] >= variety)
				{
					check = 1;
					int tmp_res = i/2 + i%2 + (j-i)/2 + (j-i)%2+1;
					if (tmp_res < result)
						result = tmp_res;
				}
		if (check == 0)
			return pleasantness.size();
		return result;
	}
};