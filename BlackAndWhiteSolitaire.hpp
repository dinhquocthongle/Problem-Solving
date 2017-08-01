#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class BlackAndWhiteSolitaire
{
public:
	int minimumTurns(string cardFront)
	{
		string temp1, temp2;
		for (int i = 0; i < cardFront.length(); i++)
		{
			if (i%2 == 0)
			{
				temp1 += 'B';
				temp2 += 'W';
			}
			else 
			{
				temp1 += 'W';
				temp2 += 'B';
			}
		}
		int tmp_result1 =0;
		int tmp_result2 =0;
		for (int i = 0; i < cardFront.length();i++)
		{
			if (temp1[i] != cardFront[i])
				tmp_result1++;
			if (temp2[i] != cardFront[i])
				tmp_result2++;
		}
		int result;
		if (tmp_result1 > tmp_result2)
			result = tmp_result2;
		else
			result = tmp_result1;
		return result;
	}
};