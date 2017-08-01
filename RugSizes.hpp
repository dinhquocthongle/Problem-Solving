#include <stdio.h>
#include <vector>
using namespace std;
class RugSizes
{
public:
	int rugCount(int area)
	{
		int l = area/2; // 32
		if ((area%2) == 1)
			l++;
		int res = 0;
		vector<int> result;
		for (int i = 1; i <= area+1; i++)
			result.push_back(0);
		for (int i = 1; i <= l; i++)
			if ((area%i) ==0)
			{
				int tmp = area / i; // tmp = 64
				if ((((tmp%2) != 0) or ((i%2) != 0) or (i == tmp)) and (result[tmp] == 0) and (result[i] == 0))
				{	
					result[tmp] = 1;
					result[i] = 1;
					res++;
				}
			}
		return res;
	}
};