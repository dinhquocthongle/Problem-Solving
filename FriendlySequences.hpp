#include <stdio.h>
#include <vector>
using namespace std;

class FriendlySequences
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
	int count(vector<int> array)
	{
		if (array.size() == 0)
			return 0;
		int result = 0;
		int count = 1;
		vector<int> digits;
		if (array[0] == 0)
			digits.push_back(0);
		while (array[0] != 0)
		{
			int d = array[0]%10;
			array[0] /= 10;
			if (digits.size() == 0)
				digits.push_back(d);
			else
			{
				int check = 1;
				for (int j = 0; j < digits.size(); j++)
					if (digits[j] == d)
						check = 0;
				if (check == 1)
					digits.push_back(d);
			}
		}
		digits = sort(digits);
		for (int i = 1; i < array.size(); i++)
		{
			vector<int> dup;
			if (array[i] == 0)
				dup.push_back(0);
			while (array[i] != 0)
			{
				int d = array[i]%10;
				array[i] /= 10;
				if (dup.size() == 0)
					dup.push_back(d);
				else
				{
					int check = 1;
					for (int j = 0; j < dup.size(); j++)
						if (dup[j] == d)
							check = 0;
					if (check == 1)
						dup.push_back(d);
				}
			}
			dup = sort(dup);
			if (dup.size() != digits.size())
			{
				digits = dup;
				for (int j = 0; j < count; j++)
					result += j;
				count = 1;
			}
			else 
			{	
				dup = sort(dup);
				int check = 1;
				for (int j = 0; j < dup.size(); j++)
					if (dup[j] != digits[j])
						check = 0;
				if (check == 0)
				{
					digits = dup;
					for (int j = 0; j < count; j++)
						result += j;
					count = 1;
				}
				else
				{
					count++;
				}
			}
		}
		for (int j = 0; j < count; j++)
			result += j;
		return result;
	}
};