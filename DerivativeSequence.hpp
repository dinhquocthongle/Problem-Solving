#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
class DerivativeSequence
{
	public:
    //this function applies te formula: a[i]= a[i] + a[i+2] - 2*a[i+1]
    //whenever n > 1
    //it reduces the time for running this program
    //when n = 1, the program applies the original formula
	vector<int> derSeq(vector<int>a, int n)
	{	
		while (n > 0) 
		{
			if (n >=2) 
			{
				for (int i = 0; i < (a.size()-2); i++) 
				{
					a[i]= a[i] + a[i+2] - 2*a[i+1];
				}
				a.pop_back();
				a.pop_back();
				n=n-2;
			}
			else
			{
				for (int i = 0; i < (a.size()-1); i++) 
				{
					a[i]= a[i+1] - a[i];
				}
				a.pop_back();
				n=n-1;
			}
		}
		for (int i = 0; i < a.size(); i++) 
		{
			cout << a[i] << endl;
		}
		return a;
	}
};
