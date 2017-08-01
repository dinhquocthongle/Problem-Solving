#include <stdio.h>
#include <vector>
using namespace std;

class TomekPhone
{
public:
	vector<int> sort(vector<int> resource)
	{
		for(int i = 0; i < resource.size()-1; i++)
		{
			int min = i;
			for (int j = i+1; j < resource.size();j++)
				if (resource[min] > resource[j])
					min = j;
			if (min != i)
			{
				int tmp = resource[min];
				resource[min] = resource[i];
				resource[i] = tmp;
			}
		}
		return resource;
	}
	//the function goes through the keysize and create a vector to store the level of pressing
	//if the keysize < the number of symbols, return -1
	//the sum is the sum of the frequencies* the level of pressing
	int minKeystrokes(vector<int> frequencies, vector<int> keySizes)
	{
		int sum_size = 0;
		int max_size = 0;
		vector<int> temp;
		for (int i = 0; i < 51; i++)
			temp.push_back(0);
		for (int i = 0; i < keySizes.size(); i++)
		{
			sum_size += keySizes[i];
			for(int j = 1; j < keySizes[i]+1; j++)
			{
				temp[j]++;
				if (max_size < (keySizes[i]+1))
					max_size = keySizes[i]+1;
			}
		}
		if (sum_size < frequencies.size())
			return -1;
		frequencies = sort(frequencies);
		int count = frequencies.size()-1;
		int result = 0;
		for (int i = 1; i < max_size; i++)
		{
			for (int j = 0; j < temp[i]; j++)
			{
				result = result + (i*frequencies[count]);
				count--;
				if (count < 0)
					return result;
			}
		}
		return result;

	}
};