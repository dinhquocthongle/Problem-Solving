#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class PrefixFreeSets
{
public:
	vector<string> sort(vector<string> resource)
	{
		for(int i = 0; i < resource.size()-1; i++)
		{
			int min = i;
			for (int j = i+1; j < resource.size();j++)
				if (resource[min].length() > resource[j].length())
					min = j;
			if (min != i)
			{
				string tmp = resource[min];
				resource[min] = resource[i];
				resource[i] = tmp;
			}
		}
		return resource;
	}
	int maxElements(vector<string> words)
	{
		words = sort(words);
		int result = words.size();
		for (int i = 0; i < words.size()-1; i++)
		{
			int check = 0;
			for (int j = i+1; j < words.size(); j++)
			{
				if (words[j].compare(0,words[i].length(),words[i]) == 0)
				{					
					check = 1;
					break;
				}
			}
			if (check == 1)
				result--;
		}
		return result;
	}
};