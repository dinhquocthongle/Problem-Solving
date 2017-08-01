#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class VeryInterestingMovie
{
public:
	int maximumPupils (vector<string> seats)
	{
		int result = 0;
		for (int i = 0; i < seats.size(); i++)
		{
			int count = 0;
			for (int j = 0; j < seats[0].length(); j++)
			{
				if (seats[i][j] == 'Y')
					count++;
				if (seats[i][j] == 'N')
					if (count != 0)
					{
						result = result + count/2 + count%2;
						count = 0;
					}
			}
			if (count != 0)
				{
					result = result + count/2 + count%2;
					count = 0;
				}
		}
		return result;
	}
};