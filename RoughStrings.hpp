#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class RoughStrings
{
public:
	struct letter
	{
		int frequence;
		int time;
	};
	int result;
	vector<letter> sort(vector<letter> resource)
	{
		for(int i = 0; i < resource.size()-1; i++)
		{
			int max = i;
			for (int j = i+1; j < resource.size();j++)
				if (resource[max].frequence > resource[j].frequence)
					max = j;
			if (max != i)
			{
				letter tmp = resource[max];
				resource[max] = resource[i];
				resource[i] = tmp;
			}
		}
		return resource;
	}
	void recursive(vector<letter> arr, int num, int r)
	{
		if (r < result)
			result = r;
		if ((result == 0) or (num == 0))
			return;
		if (arr[0].time*arr[0].frequence <= num)
		{
			vector<letter> temp = arr;
			temp.erase(temp.begin());
			recursive(temp, num- arr[0].time*arr[0].frequence, temp[temp.size()-1].frequence - temp[0].frequence);
		}
		if (arr[arr.size()-1].time <= num)
		{
			if (arr[arr.size()-1].time *(arr[arr.size()-1].frequence - arr[arr.size()-2].frequence) <= num)
			{
				vector<letter> temp = arr;
				temp[temp.size() -2].time += temp[temp.size()-1].time;
				temp.erase(temp.end()-1);
				cout << temp[temp.size()-1].frequence - temp[0].frequence << endl;
				recursive(temp, num- arr[arr.size()-1].time *(arr[arr.size()-1].frequence - arr[arr.size()-2].frequence), temp[temp.size()-1].frequence - temp[0].frequence);
			}
			else
			{
				vector<letter> temp = arr;
				temp[temp.size() -1].frequence = temp[temp.size() -1].frequence - (num / temp[temp.size()-1].time);
				recursive(temp, num % temp[temp.size()-1].time, temp[temp.size()-1].frequence - temp[0].frequence);
			}
		}
	}
	int minRoughness(string s, int n)
	{
		vector<letter> l;
		for (int i = 0; i < 26; i++)
		{
			int count = 0;
			for (int j = 0; j < s.size(); j++)
				if ((int)s[j] == 97+i)
					count++;
			if (count != 0)
			{
				int check = 0;
				for (int j = 0; j < l.size(); j++)
					if (l[j].frequence == count)
					{
						l[j].time++;
						check = 1;
					}
				if (check == 0)
				{
					letter tmp;
					tmp.frequence = count;
					tmp.time = 1;
					l.push_back(tmp);
				}
			}
		}
		l = sort(l);
		//for (int i = 0; i < l.size(); i++)
		//	cout << l[i].frequence << endl;
		result = l[l.size()-1].frequence - l[0].frequence;
		recursive(l,n,result);
		return result;
	}
};