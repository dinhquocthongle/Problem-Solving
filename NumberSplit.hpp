#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class NumberSplit
{
public:
	int result;
	//the number splits into digits and store in a vector
	//then produce the numbers from digits
	//and call the next recursive function 
	//when the number is < 10, check for the count
	void f(int resource, int count)
	{
		if (resource < 10)
		{
			if (count > result)
				result = count;
			return;
		}
		int temp = resource;
		vector<int> digit;
		vector<int> next_res;

		while (temp > 0)
		{
			digit.insert(digit.begin(),temp%10);
			temp /=10;
		}
		for (int i = 2; i < digit.size()+1; i++)
		{
			vector<int> nums_start;
			for (int j = 0; j < i; j++)
				nums_start.push_back(j);
			nums_start.push_back(digit.size());
			int move = 1;
			while (move > 0)
			{
				//vector for numbers
				vector<int> nums;
				for (int j = 0; j < i; j++)
					nums.push_back(0);
				//
				for(int j = 0; j < nums_start.size()-1; j++)
				{
					for (int k =nums_start[j]; k < nums_start[j+1]; k++)
					{
						nums[j] = nums[j]*10 + digit[k];
					}
				}
				int res = 1;
				//sum
				for (int j = 0; j < nums.size(); j++)
					res = res* nums[j];
				if (find(next_res.begin(),next_res.end(),res) == next_res.end())
				{
					next_res.push_back(res);
					f(res,count+1);
				}
				move = nums_start.size()-2;
				while ((move > 0) and (nums_start[move] == (nums_start[move+1]-1)))
					move--;
				if (move <= 0)
					break;
				nums_start[move]++;
				if (move != nums_start.size()-2)
					for (int j = move+1;j < nums_start.size()-1; j++)
						nums_start[j] = nums_start[j-1]+1;
			}
		}
	}
	int longestSequence(int start)
	{
		result = 0;
		f(start,1);
		return result;
	}
};