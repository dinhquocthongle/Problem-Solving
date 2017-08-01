#include <stdio.h>
#include <stdlib.h>
using namespace std;
class FibonacciDiv2
{
	public:
    //the function keeps calculating the fib number until it's greater than n
    //if n = the last fib number, the distance = 0
    //otherwise, the program finds the smaller distance between n with the smaller and larger fib numbers
	int find(int n) 
	{
		int fib = 1;
		int fib0= 0;
		int fib1= 1;
		if (n == 1) 
			return 0;
		while (fib < n) 
		{
			fib = fib0 + fib1;
			fib0 = fib1;
			fib1 = fib;
		}
		if (n == fib1) 
			return 0;
		int step1 = abs(fib0 - n);
		int step2 = abs(fib1 - n);
		if (step1 > step2)
			return step2;
		else 
			return step1;
	}
};
