#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class ProcessScheduler
{
public:
	int bestTime(vector<int> t, vector<string> prec)
	{
		vector<int> sum_time;
		vector<int> mark;
		for (int i = 0; i < t.size(); i++)
		{
			mark.push_back(0);
			sum_time.push_back(0);
		}
		int check = 0;
		while (check == 0)
		{
			int check_loop = 1;
			for(int i = 0; i < t.size(); i++)
			{
				if (mark[i] == 0)
				{
					int check_e = 0;
					for (int j = 0; j < prec[i].length(); j++)
					{
						if ((prec[i][j] == 'Y') and (mark[j] == 0))
						{
							check_e = 1;
						}
					}
					if (check_e == 0)
					{
						check_loop = 0;
						mark[i] = 1;
						int ti = 0;
						for (int j = 0; j < prec[i].length(); j++)
						{
							if (prec[i][j] == 'Y')
								if(ti < sum_time[j])
									ti = sum_time[j];
						}
						sum_time[i] = ti + t[i];
					}
				}
			}
			if (check_loop == 1)
				return -1;
			check = 1;
			for(int i = 0; i < t.size(); i++)
				if(mark[i] == 0)
					check = 0;
		}
		int result = 0;
		for (int i = 0; i < t.size(); i++)
		{
			if (result < sum_time[i])
				result = sum_time[i];
		}
		return result;
	}
};