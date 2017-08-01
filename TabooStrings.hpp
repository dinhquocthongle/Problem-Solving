#include <stdio.h>
#include <vector>
using namespace std;

class TabooStrings
{
public:
	//this one is too hard...
	//the idea is about considering 2 last elements
	//if those elements (called "same") are the same, there are 3 ways to put the next element in.
	//else, there are only 2 ways. (AB_ we can only put A or B) (called "diff")
	//after put the next element in, there are 1/3 number of ways in "same" produces the next "same" (means 2 last elements is the same)
	//2/3 numbers of ways produces "diff"
	//for diff, 50% numbers of ways produces the next "diff" and another 50% produces next "same"
	//get the next same and redo for n times
	long long countNotTaboo(int n)
	{
		long long same, diff;
		if (n == 1)
			return 3;
		else if (n == 2)
			return 9;
		same = 3;
		diff = 6;
		for (int i = 2; i < n; i++)
		{
			diff *= 2;
			same *= 3;
			int same_temp, diff_temp;
			same_temp = same/3 + diff/2;
			diff_temp = 2* same/3 + diff/2;
			same = same_temp;
			diff = diff_temp;
		}
		long long result = same + diff;
		return result;
	}
};