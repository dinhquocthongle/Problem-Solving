#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class SentenceDecomposition
{
public:
	struct letter
	{
		char c;
		int frequence;
	};
	struct partition
	{
		int from;
		int to;
		int price;
	};
	vector<partition> p;
	int l;
	int result;

	string sort(string resource)
	{
		for(int i = 0; i < resource.length()-1; i++)
		{
			int max = i;
			for (int j = i+1; j < resource.length();j++)
				if (resource[max] > resource[j])
					max = j;
			if (max != i)
			{
				char tmp = resource[max];
				resource[max] = resource[i];
				resource[i] = tmp;
			}
		}
		return resource;
	}
	void recursive(partition curr, int pr)
	{
		if ((curr.to == l) or (result == 0))
		{
			if (result > pr)
				result = pr;
			return;
		}
		for (int i = 0; i < p.size(); i++)
		{
			int temp = pr;
			if (p[i].from == curr.to)
			{
				temp += p[i].price;
				recursive(p[i], temp);
			}
		}
	}
	int decompose(string sentence, vector<string> validWords)
	{
		l = sentence.length();
		result = 10000;
		for (int i = 0; i < validWords.size(); i++)
		{
			string c = sort(validWords[i]);
			if (l >= c.length())
			{
				for(int j = 0; j < sentence.length()- validWords[i].length()+1; j++)
				{
					string temp;
					for (int k = 0; k < validWords[i].length(); k++)
					{
						temp += sentence[j+k];
					}
					temp = sort(temp);
					if (c.compare(temp) == 0)
					{
						int v = 0;
						for (int k = 0; k < validWords[i].length(); k++)
						{
							if (sentence[j+k] != validWords[i][k])
							{
								v++;
							}
						}
						partition t;
						t.from = j;
						t.to = j + validWords[i].length();
						t.price = v;
						p.push_back(t);
					}
				}
			}
		}
		vector<partition> start;
		for (int i = 0; i < p.size(); i++)
			if (p[i].from == 0) 
				start.push_back(p[i]);

		for (int i = 0; i < start.size(); i++)
			recursive(start[i], start[i].price);
		p.clear();
		if (result == 10000)
			return -1;
		return result;
	}
};