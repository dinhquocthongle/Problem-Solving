#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class BlackAndRed
{
	public:
    //the function declares a count vector
    //the vector starts from the first card
    //if the card is B, the count increases by 1
    //otherwise, it decreases by 1
    //
	int cut(string deck)
	{
		vector<int> count;
		for (int i = 0; i < deck.length(); i++) 
		{
			count.push_back(0);
		}
		int result = 0;
		int min = 0;
		if (deck[0] == 'B') 
			count[0]++;
		else 
			count[0]--;
		if (min > count[0]) 
			{
				result = 1;
				min = count[0];
			}
		for (int i = 1; i < deck.length(); i++)
		{
			count[i] = count[i-1];
			if (deck[i] == 'B') 
			count[i]++;
			else
			count[i]--;
			if (min > count[i]) 
			{
				result = i+1;
				min = count[i];
			}
		}
		return result;
	}
};
