#include <stdio.h>
#include <string.h>
using namespace std;

class NonsenseNumerals
{
	public:
	//this function set some conditions for x
	//when x <= 10, return the relevant value from the name array
	//when x <= 19, find x % 10 then produce the result
	//otherwise, find x/10 and x%10, then produce the result 
	string name(int x)
	{
		string n[10] = {"unu", "du", "tri", "kvar", "kvin", "ses", "sep", "ok", "nau", "dek"};
		if (x <= 10)
			return n[x-1];
		else if ( x <= 19 )
		{
			int temp = x % 10;
			string result = n[9] + " " + n[temp-1];
			return result; 
		}
		else
		{
			int temp1 = x / 10;
			int temp2 = x % 10;
			string result;
			if (temp2 != 0)
				result = n[temp1-1] + n[9] + " " + n[temp2-1];
			else 
				result = n[temp1-1]+ n[9];
			return result;
		}
	}
};
