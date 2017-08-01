#include <stdio.h>
using namespace std;
 
 
class Inchworm
{
	public:
	int res;
	//calculate the gcd...
	int gcd(int a, int b) 
	{
		if (b == 0)
			return a;
		return gcd(b, a%b);
	}
	//...to produce lcm
	int lcm(int a, int b) 
	{
		return a*b/gcd(a,b);
	}
	//this function runs based on the formula which is
	//result = branch/lcm(rest,leaf) + 1
	//because when the worm begins, she will eat another leaf after lcm(rest,leaf)
	//so the num of leaves she eats in the trip will be branch/lcm(rest,leaf);
	//+1 leaf she ate at the beginning
	int lunchtime(int branch, int rest, int leaf)
	{
		//to calculate the lcm, the program need to sort out the larger number between leaf and rest
		int a, b, lcm_result;
		if (rest > leaf) 
		{
			a = rest;
			b = leaf; 
		}
		else 
		{
			a = leaf;
			b = rest;
		}
		//calculate the lcm
		lcm_result = lcm(a,b);
		//calculate the result
		res = branch/lcm_result + 1;
		return res;  // return your result
  	}
};
