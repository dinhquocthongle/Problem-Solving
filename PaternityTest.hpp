#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class PaternityTest
{
public:
	vector<int> possibleFathers(string child, string mother, vector<string> men)
	{
		vector<int> result;
		for(int i = 0; i < men.size(); i++)
		{
			int check = 1;
			int count = 0;
			for (int j = 0; j < child.length(); j++)
			{
				if ((child[j] != mother[j]) and (child[j] != men[i][j]))
					check = 0;
				else if (child[j] == men[i][j])
					count++;
			}
			if ((check == 1) and (count >= (child.length()/2)))
			{
				cout << i<< endl;
				result.push_back(i);
			}
		}
		return result;
	}
};