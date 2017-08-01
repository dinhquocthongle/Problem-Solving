#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm> 
#include <vector>
using namespace std;

class AlternateColors
{
	public:
	struct color
	{
		long num;
		string name;
	};
	//instead of have a for loop for 3*(10^12) times
	//this function will solve the problem manually
	//firstly, it declares 2 vectors, one for the name of color, one for the number of balls
	//then it sorts the balls' vector
	//from that, the function manually find out the result
	string getColor(long r, long g, long b, long k)
	{
		vector<string> n;
		n.push_back("BLUE");
		n.push_back("RED");
		n.push_back("GREEN");
		vector<color> c;
		color temp;
		temp.num = r;
		temp.name = "RED";
		c.push_back(temp);
		temp.num = g;
		temp.name = "GREEN";
		c.push_back(temp);
		temp.num = b;
		temp.name = "BLUE";
		c.push_back(temp);
		for (int i = 0; i < 2; i++)
		{
			for (int j = i+1; j < 3; j++)
			{
				if (c[i].num > c[j].num)
				{
					temp = c[i];
					c[i] = c[j];
					c[j] = temp;
				}
			}
		}
		int result;
        int check = 0;
		if (k <= (c[0].num*3)) 
		{
			result = k % 3;
			return n[result];
		}
		else
		{
			k = k - 3*c[0].num;
            int tmp = c[0].num;
			for (int i = 0; i < 3; i++)
			{
				if (n[i].compare(c[0].name) == 0)
					n.erase(n.begin() + i);
				c[i].num = c[i].num - tmp;
			}
			//special case, when BLUE is gone, the function needs to rearrange the sequence of the color
			//to make sure the result is correct
			if (c[0].name == "BLUE") 
			{
                check = 1;
				string dup = n[0];
				n[0] = n[1];
				n[1] = dup;
			}
		}
		if (k <= (c[1].num*2)) 
		{
            cout << "ok";?
			result = k % 2;
			return n[result];
		}
		else
		{
            if (check == 1)
                return "RED";
			return c[2].name;
		}
	}

};
