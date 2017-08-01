#include <stdio.h>
#include <vector>
using namespace std;
class FewestFactors
{
	public:
	//function k produce the numbers from the provided digits by recursion
	//to calculate the result
	//for each number, the function have a for loop from 1 to the number and count the number of factor
	vector<long> k (vector<int>resource, long num)
	{
		vector<long> res;
		if (resource.size() == 1)
		{
			num = num*10 + resource[0];
			res.push_back(num);
			return res;
		}
		vector<long> t;
		for (int i = 0; i < resource.size(); i++)
		{
			vector<int> dup = resource;
			int tmp = num*10;
			tmp += resource[i];
			dup.erase(dup.begin()+i);
			t = k(dup,tmp);
			for(int j = 0; j < t.size(); j++)
				res.push_back(t[j]);
		}
		return res;
	}

	int number(vector<int> digits)
	{
		vector<long> num;
		num = k(digits,0);
		long min = 0;
		long min_factor = 1000000;
		for (int i = 0; i < num.size(); i++)
		{
			int count = 0;
			for (int j = 1; j < num[i]; j++)
			{
				if ((num[i]%j) == 0)
				{
					count++;
				}
			}
			if (count == min_factor)
			{
				if (min > num[i])
					min = num[i];
			}
			else if (count < min_factor)
			{
				min = num[i];
				min_factor = count;
			}
		}
		return min;
	}
};