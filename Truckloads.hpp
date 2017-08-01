#include <stdio.h>
using namespace std;

class Truckloads
{
public:
	//this function find the result by call its subproblems until it reaches the base case (recursive function)
	int recursion(int n, int s)
	{
		if (n <= s)
			return 1;
		int tmp1, tmp2;
		tmp1 = n/2;
		tmp2 = n/2;
		if ((n%2) != 0)
			tmp2++;
		return recursion(tmp1,s)+recursion(tmp2,s);

	}
	int numTrucks(int numCrates, int loadSize)
	{
		return recursion(numCrates,loadSize);
	}
};