#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <stdlib.h> 
using namespace std;

class RockStar
{
public:
	struct type
	{
		int num;
		string name;
	};
	int getNumSongs(int ff, int fs, int sf, int ss)
	{
		int check = 1;
		int result = 1;
		string song;
		if (ff > 0)
		{
			ff--;
			song = "ff";
		}
		else if (fs > 0)
		{
			fs--;
			song = "fs";
		}
		else if (ss > 0)
		{
			ss--;
			song = "ss";
		}
		else if (sf > 0)
		{
			sf--;
			song = "sf";
		}
		while (check == 1)
		{
			if (song == "ff")
			{
				if (ff > 0)
				{
					ff--;
					song = "ff";
					result++;
				}
				else if (fs > 0)
				{
					fs--;
					song = "fs";
					result++;
				}
				else 
					check = 0;
			}
			else if (song == "fs")
			{
				if (ss > 0)
				{
					ss--;
					song = "ss";
					result++;
				}
				else if (sf > 0)
				{
					sf--;
					song = "sf";
					result++;
				}
				else 
					check = 0;
			}
			else if (song == "ss")
			{
				if (ss > 0)
				{
					ss--;
					song = "ss";
					result++;
				}
				else if (sf > 0)
				{
					sf--;
					song = "sf";
					result++;
				}
				else 
					check = 0;
			}
			else if (song == "sf")
			{
				if (fs > 0)
				{
					fs--;
					song = "fs";
					result++;
				}
				else 
					check = 0;
			}
		}
		return result;
	}
};