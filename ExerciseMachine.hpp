#include <stdio.h>
#include <string.h>
using namespace std;

class ExerciseMachine
{
public:
	//calculate the gcd...
	int gcd(int a, int b) 
	{
		if (b == 0)
			return a;
		return gcd(b, a%b);
	}
	//this function calculate the time in second and pass it to gcd function to produce result
	int getPercentages(string time)
	{
		int hour = ((int)time[0]-48)*10 + (int)time[1]-48;
		int min = ((int)time[3]-48)*10 + (int)time[4]-48;
		int sec = ((int)time[6]-48)*10 + (int)time[7]-48;
		sec = sec + ((hour*60)+min)*60;

		int a, b;
		if (sec > 100)
		{
			a = sec;
			b = 100;
		}
		else
		{
			a = 100;
			b = sec;
		}
		return (gcd(a,b)-1);
	}
	
};