#include <stdio.h>
using namespace std;
 
 
class EggCartons
{
	public:
	//to get the min cartons, the program need the get maximum number of 8 eggs' carton
	//it's only possible when n % 8 == 0
	//so the idea is: check for n >= 6
	//if it's, check for n % 8 == 0
	//if it's not, the program get 1 more 6 eggs' carton and start again 
	int minCartons(int n) 
	{
		int res = 0;
		while (n >= 6) 
		{
			if (n % 8 == 0) 
			{
				res = res + (n/8);
				n = 0;
			} 
			else
			{
				res++;
				n = n - 6;
			}
		}
		//check for the number of eggs left behind
		if (n != 0)
			return -1;
		return res;
	}
};
