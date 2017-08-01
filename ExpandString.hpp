#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class ExpandString
{
	public:
	int howLong(string s)
	{
		vector<int> value;
		vector<int> t;
		t.push_back(1);
		value.push_back(0);
		for (int i= 0; i < s.length(); i++)
		{
			if ( i+1 < s.length())
			{
				if (s[i+1] == '(')
				{
					t.push_back(s[i]-48);
					value.push_back(0);
				}
			}
			if(s[i] == ')')
			{
				for (int j= 0; j < value.size(); j++)
				{
					cout << value[j] << " " << t[j];
					cout << endl;
				}
				value[value.size()-2] = t[t.size()-1]*value[value.size()-1]+ value[value.size()-2];
				t.erase(t.begin() + t.size()-1);
				value.erase(value.begin() + value.size()-1);
			}
			else if ((s[i] != '(') and (s[i+1] != '('))
			{
				cout << s[i];
				value[value.size()-1]++;
			}
		}
		int sum = 0;
		for(int i = 0; i < value.size();i++)
		{
			sum += value[i];
		}
		return sum;
	}
};
