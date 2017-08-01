#include <stdio.h>
#include <vector>
using namespace std;
class MonstersValley2
{
public:
	int result;
	void find(long s,int p,int index,vector<int> dread, vector<int> price)
	{
		if (index == dread.size())
		{
			if (result > p)
				result = p;
			return;
		}
		find(s+dread[index],p+price[index],index+1,dread, price);
		if(s >= dread[index])
			find(s,p,index+1, dread,price);
		return;
	}
	int minimumPrice(vector<int> dread, vector<int> price)
	{
		result = 100000;
		long scariness = dread[0];
		int p = price[0];
		find(scariness,p,1,dread,price);
		return result;
	}
};
