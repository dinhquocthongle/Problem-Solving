#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class CellRemoval
{
public:
	vector<int> index;
	vector<int> value;
	int countCell(vector<int> parent, int r)
	{
		vector<int> result;
		for (int i = 0; i < parent.size(); i++)
		{
			if (parent[i] == r)
			{
				result.push_back(countCell(parent,i));
			}
		}
		if (result.size() == 0)
		{
			index.push_back(r);
			value.push_back(1);
			return 1;
		}
		else
		{
			int res = 0;
			for (int i = 0; i < result.size(); i++)
				res += result[i];
			index.push_back(r);
			value.push_back(res);
			return res;
		}
	}
	int cellsLeft(vector<int> parent, int deletedCell)
	{
		int root;
		for (int i = 0; i < parent.size(); i++)
		{
			if (parent[i] == -1)
			{
				root = i;
			}
		}
		int total = countCell(parent,root);
		int rm;
		for (int i = 0; i < index.size(); i++)
			if (index[i] == deletedCell)
				rm = value[i];
		return total-rm;
	}
};