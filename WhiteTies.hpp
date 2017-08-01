#include <stdio.h>
#include <vector>
using namespace std;

class WhiteTies
{
	public:
	//this function go through the whole count array
	//check for error and produce the sum
	//the result = sum / (number of people -1)
	//because person 1 can only see (number of people -1) people
	//if (sum % (count.size()-1) != 0), that means there is an unvalid situation
	//the function also need to check if the result < the maximum of count
	//if there are more than 2 people see (number of people -1) people wearing white ties, result have to be (number of people)
	int whiteNumber(vector<int> count)
	{
		int sum=0;
		int max = count[0];
		int count_max = 0;
		for(int i = 0; i < count.size(); i++) 
		{
			if (count[i] == (count.size()-1))
				count_max++;
			if (count[i] >= count.size())
				return -1;
			if (max < count[i])
				max = count[i];
			sum += count[i];
		}
		if (sum % (count.size()-1) != 0)
			return -1;
		int result = sum/ (count.size()-1);
		if (result < max)
			return -1;
		if (count_max > 1)
			if (result != count.size())
				return -1;
		return result;
	}
};
