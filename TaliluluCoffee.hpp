#include <stdio.h>
#include <vector>
using namespace std;

class TaliluluCoffee
{
public:
	vector<int> sort(vector<int> resource)
	{
		for(int i = 0; i < resource.size()-1; i++)
		{
			int max = i;
			for (int j = i+1; j < resource.size();j++)
				if (resource[max] < resource[j])
					max = j;
			if (max != i)
			{
				int tmp = resource[max];
				resource[max] = resource[i];
				resource[i] = tmp;
			}
		}
		return resource;
	}

	int maxTip(vector<int> tips)
	{
		tips = sort(tips);
		int result = 0;
		for (int i = 0 ;i < tips.size(); i++)
			if (tips[i] -i > 0)
				result += tips[i]-i;
		return result;
	}
};