#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class HouseBuilding
{
public:
	//the function finds the highest and lowest values in the area
	//a for loop will scan through the area and find the result
	int getMinimum(vector<string> area)
	{
		vector<int> level;
		int highest, lowest;
		highest = (int)area[0][0]-48;
		lowest = (int)area[0][0]-48;
		for (int i = 0; i < area.size(); i++)
			for (int j = 0; j < area[i].length(); j++)
			{
				int temp = (int)area[i][j]-48;
				level.push_back((int)area[i][j]-48);
				if (highest < temp)
					highest = temp;
				if (lowest > temp)
					lowest = temp;
			}
		int result = 1000000;
		if ((lowest == highest-1) or (lowest == highest))
			return 0;
		for (int i = lowest; i < highest; i++)
		{
			int temp_result = 0;
			for (int j = 0; j < level.size(); j++)
			{
				if (abs(level[j]-i) > abs(level[j]-(i+1)))
					temp_result += abs(level[j]-(i+1));
				else
					temp_result += abs(level[j]-i);
			}
			if (temp_result < result)
				result = temp_result;
		}
		return result;
	}
};