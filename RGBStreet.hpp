#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class RGBStreet
{
public:
	int result;
	//when the current house is red, the function call the next functions for the other color
	//when it reaches the last house, the function checks for the result
	void find(vector<int> r, vector<int> g, vector<int> b, int index, string color, int price)
	{
		if (index == (r.size()-1))
		{
			if (price < result)
				result = price;
			return;
		}
		if (color == "red")
		{
			find(r,g,b, index+1, "green", price+ g[index+1]);
			find(r,g,b, index+1, "blue", price+ b[index+1]);
		}
		if (color == "green")
		{
			find(r,g,b, index+1, "red", price+ r[index+1]);
			find(r,g,b, index+1, "blue", price+ b[index+1]);
		}
		if (color == "blue")
		{
			find(r,g,b, index+1, "green", price+ g[index+1]);
			find(r,g,b, index+1, "red", price+ r[index+1]);
		}

	}
	int estimateCost(vector<string> houses)
	{
		result = 100000;
		vector<int> red, green, blue;
		for (int i = 0; i < houses.size(); i++)
		{
			int temp = 0;
			int check_color = 1;
			for (int j = 0; j < houses[i].length(); j++)
			{
				if (houses[i][j] == ' ')
				{
					if (check_color == 1)
						red.push_back(temp);
					else
						green.push_back(temp);
					check_color++;
					temp = 0;
				}
				else 
				{
					temp = temp*10 + (int)houses[i][j] -48;
				}
			}
			blue.push_back(temp);
		}
		find(red, green, blue, 0, "red",red[0]);
		find(red, green, blue, 0, "green",green[0]);
		find(red, green, blue, 0, "blue",blue[0]);
		return result;
	}
};