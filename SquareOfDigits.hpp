#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

class SquareOfDigits
{
public:
	int getMax(vector<string> data)
	{
		int max_length = 0;
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[i].length(); j++)
			{
				for (int k = j; k < data[i].length(); k++)
				{
					if ((data[i][k] == data[i][j]) and (k-j > max_length))
					{
						if ((i+k-j < data.size()) and (data[i+k-j][k] == data[i+k-j][j]) and (data[i][k] == data[i+k-j][j]))
							max_length = k-j;
					}
				}
			}
		}
		max_length++;
		return max_length*max_length;
	}
};