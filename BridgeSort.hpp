#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class BridgeSort
{
public:
	struct card
	{
		int value;
		char suit;
	};
	vector<card> sort(vector<card> resource)
	{
		for(int i = 0; i < resource.size()-1; i++)
		{
			int max = i;
			for (int j = i+1; j < resource.size();j++)
				if (resource[max].value > resource[j].value)
					max = j;
			if (max != i)
			{
				card tmp = resource[max];
				resource[max] = resource[i];
				resource[i] = tmp;
			}
		}
		return resource;
	}
	string sortedHand(string hand)
	{
		vector<card> c;
		for (int i = 0; i < hand.size(); i = i + 2)
		{
			card temp;
			temp.suit = hand[i];
			temp.value = (int)hand[i+1] -48;
			if (temp.value > 9)
			{
				if (hand[i+1] == 'T')
					temp.value = 10;
				else if (hand[i+1] == 'J')
					temp.value = 11;
				else if (hand[i+1] == 'Q')
					temp.value = 12;
				else if (hand[i+1] == 'K')
					temp.value = 13;
				else if (hand[i+1] == 'A')
					temp.value = 14;
			}
			c.push_back(temp);
		}
		c = sort(c);
		char s[] = {'C','D','H','S'};
		string result;
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < c.size(); i++)
			{
				if (c[i].suit == s[j])
				{
					result += s[j];
					if (c[i].value < 10)
						result += (char)(c[i].value+48);
					else if (c[i].value == 10)
						result += 'T';
					else if (c[i].value == 11)
						result += 'J';
					else if (c[i].value == 12)
						result += 'Q';
					else if (c[i].value == 13)
						result += 'K';
					else if (c[i].value == 14)
						result += 'A';
				}
			}
		}
		return result;
	}
};