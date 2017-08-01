#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class BigBurger
{
public:
	int maxWait(vector<int> arrival, vector<int> service)
	{
		int max = 0;
		int current = 0;
		for (int i = 0; i < arrival.size(); i++)
		{
			if (current > arrival[i])
			{
				int wait = current - arrival[i];
				if (wait > max)
					max = wait;
				current += service[i];
			}
			else
				current = arrival[i] + service[i];
		}
		return max;
	}
};