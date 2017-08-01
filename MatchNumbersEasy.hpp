#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h> 
#include <sstream>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

class MatchNumbersEasy
{
public:
	struct value
	{
		int num;
		int m;
	};
	vector<value> sort(vector<value> resource)
	{
		for(int i = 0; i < resource.size()-1; i++)
		{
			int max = i;
			for (int j = i+1; j < resource.size();j++)
				if (resource[max].m > resource[j].m)
					max = j;
			if (max != i)
			{
				value tmp = resource[max];
				resource[max] = resource[i];
				resource[i] = tmp;
			}
		}
		return resource;
	}
	string maxNumber(vector<int> matches, int n)
	{
		vector<value> v;
		stringstream ss;
		int sum_digit = 0;
		for (int i = 0; i < matches.size(); i++)
		{
			value temp;
			temp.num = i;
			temp.m = matches[i];
			v.push_back(temp);
		}
		value t;
		t.num = 10;
		t.m = 1000;
		v.push_back(t);
		v = sort(v);
		string output;
		if ((v[0].num == 0) and (n >= v[1].m))
		{
			n -= v[1].m;
			output += (char)(v[1].num+48);
			int temp = n/v[0].m;
			for (int i = 0; i < temp; i++)
				output += (char)(v[0].num+48);
			n = n%v[0].m;
		}
		else if (v[0].num != 0)
		{
			int temp = n/v[0].m;
			for (int i = 0; i < temp; i++)
				output += (char)(v[0].num+48);
			n = n%v[0].m;
		}
		else if ((v[0].num == 0) and (n < v[1].m))
		{
			int temp = n/v[0].m;
			output += (char)(v[0].num+48);
			return output;
			n = n%v[0].m;
		}
		//cout << output;
		for (int i = 0; i < output.length(); i++)
		{
			int digit = (int)output[i]-48;
			//cout << digit << " " << output[i] << endl;
			for (int j = matches.size()-1; j > digit; j--)
				if (n+matches[digit] >= matches[j])
				{
					//cout << j << endl;
					output.erase(output.begin()+i);
					output.insert(i,1,(char)(j+48));
					n = n+matches[digit] - matches[j];
					break;
				}
		}
		return output;
	}
};