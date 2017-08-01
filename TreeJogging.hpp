#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class TreeJogging
{
public:
	int timesAround(int n, vector<int> d)
	{
		int result = 1;
		for (int i = 1; i < d.size(); i++)
		{
			if (d[i] <= d[i-1])
				result++;
		}
		return result;
	}
};