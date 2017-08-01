#include <stdio.h>
#include <vector>
using namespace std;

class FairWorkload
{
public:
	int result, min_result;
	int check;
	void process(vector<int> f, int w, int w_th, vector<int> partition)
	{
		if (check == 1)
			return;
		if (w_th == w)
		{
			vector<int> dup = partition;
			dup.push_back(f.size());
			int max = 0;
			for (int i = 0; i < dup.size()-1; i++)
			{
				int s =0;
				for (int j = dup[i]; j < dup[i+1];j++)
					s += f[j];
				if (max < s)
					max = s;
			}
			if (max < result)
			{
				if (max == min_result)
					check = 1;
				result = max;
			}
			return;
		}
		int start = partition[partition.size()-1]+1;
		for (int i = start; i < f.size()-w+w_th+1; i++)
		{
			vector<int> dup = partition;
			dup.push_back(i);
			process(f,w,w_th+1,dup);
		}
	}
	int getMostWork(vector<int> folders, int workers)
	{
		int sum = 0;
		check = 0;
		for (int i = 0; i< folders.size();i++)
			sum+=folders[i];
		result = 10000000;
		min_result = sum/workers;
		vector<int> p;
		p.push_back(0);
		process(folders, workers,1,p);
		return result;
	}
};