#include <stdio.h>
#include <vector>
using namespace std;

class ShipBoxes
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
	int bestCost(vector<int> box1, vector<int> box2)
	{
		int result = 1300000000;
		for (int i =0; i < box1.size(); i++)
		{
			int new_height;
			vector<int> dim;
			for (int j = 0; j < box2.size(); j++)
			{
				new_height = box1[i] + box2[j];
				vector<int> dup_box1 = box1;
				dup_box1.erase(dup_box1.begin()+i);
				vector<int> dup_box2 = box2;
				dup_box2.erase(dup_box2.begin()+j);
				dup_box1 = sort(dup_box1);
				dup_box2 = sort(dup_box2);
				vector<int> dim;
				for (int k = 0; k < dup_box2.size(); k++)
				{
					if (dup_box1[k] > dup_box2[k])
						dim.push_back(dup_box1[k]);
					else 
						dim.push_back(dup_box2[k]);
				}
				dim.push_back(new_height);
				dim = sort(dim);
				dim.insert(dim.begin(), dim.begin(), dim.end());
				int r;
				for (int i = 0; i < dim.size()/2; i++)
				{
					r = dim[i]*dim[i+1]*4 + (dim[i]+dim[i+1])*dim[i+2]*2;
					if (r < result)
						result = r;
				}
			}
		}
		return result;
	}
};