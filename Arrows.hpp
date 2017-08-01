#include <stdio.h>
#include <string>
using namespace std;

class Arrows
{
public:
	//this function goes through the string and searches for arrow
	//for each arrow it found, it sorts out the length and find the longest
	int longestArrow(string s)
	{
		int max= 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '>')
			{
				int count = 1;
				if ((i-1) >= 0)
				{
					if ((s[i-1] != '<') and (s[i-1] != '>'))
					{
						char tmp = s[i-1];
						int n = i-1;
						while ((s[n] == tmp) and (n >= 0))
						{
							n--;
							count++;
						}
					}
				}
				if (max < count)
					max = count;
			}
			else if (s[i] == '<')
			{
				int count = 1;
				if ((i+1) < s.length())
				{
					if ((s[i+1] != '<') and (s[i+1] != '>'))
					{
						char tmp = s[i+1];
						int n = i+1;
						while ((s[n] == tmp) and (n < s.length()))
						{
							n++;
							count++;
						}
					}
				}
				if (max < count)
					max = count;
			}
		}
		if (max == 0)
			return -1;
		return max;
	}
};