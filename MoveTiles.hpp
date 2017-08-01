#include <stdio.h>
#include <vector>
#include <stdlib.h> 
using namespace std;

class MoveTiles
{
public:
	//the function will look for the stacks got more tiles then expected
	//from there, it scans back to the left to fill the stacks
	//if the left' stacks are full, start to fill on the right
	int get(vector<int> a, vector<int> b)
	{
		int sum_a = 0;
		int sum_b = 0;
		for (int i =0; i < a.size(); i++)
		{
			sum_b += b[i];
			sum_a += a[i];
		}
		if (sum_a != sum_b)
			return -1;
		int result = 0;
		for (int i =0; i < a.size();i++)
		{
			if (a[i] > b[i])
			{
				int temp1 = i;
				int temp2 = i;
				int temp_value = a[i] - b[i];
				a[i] = b[i];
				while ((temp_value != 0) and (temp1 > 0))
				{
					temp1--;
					if (a[temp1] < b[temp1])
					{
						if (b[temp1] - a[temp1] >= temp_value)
						{
							result = result + temp_value*abs(temp1 - i);
							a[temp1] += temp_value;
							temp_value = 0;
						}
						else 
						{
							temp_value = temp_value - (b[temp1] - a[temp1]);
							result = result + (b[temp1] - a[temp1])*abs(temp1 - i);
							a[temp1] = b[temp1];
						}
					}
				}
				while ((temp_value != 0) and (temp2 < a.size()))
				{
					temp2++;
					if (a[temp2] < b[temp2])
					{
						if (b[temp2] - a[temp2] >= temp_value)
						{
							result = result + temp_value*abs(temp2 - i);
							a[temp2] += temp_value;
							temp_value = 0;
						}
						else 
						{
							temp_value = temp_value - (b[temp2] - a[temp2]);
							result = result + (b[temp2] - a[temp2])*abs(temp2 - i);
							a[temp2] = b[temp2];
						}
					}
				}
			}
		}
		return result;
	}
};