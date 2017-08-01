#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class CorporationSalary
{
public:
	struct employee 
	{
		int salary;
		vector<int> boss;
	};
	long totalSalary(vector<string> relations)
	{
		set<int> done;
		vector<employee> e;
		int count = 0;
		for (int i = 0; i < relations.size(); i++)
		{
			employee x;
			for (int j = relations[i].length()-1; j >= 0; j--)
			{
				if (relations[i][j] == 'Y')
				{
					x.boss.push_back(j);
				}
			}
			if (x.boss.size() == 0)
			{
				count++;
				done.insert(i);
				x.salary = 1;
			}
			else 
				x.salary = -1;
			e.push_back(x);
		}
		int i = 0;

		while (count < relations.size())
		{
			//cout << "AAAAAA   " << i << endl;
			if (e[i].salary == -1)
			{
				int check = 0;
				for (int j = 0; j < e[i].boss.size(); j++)
				{
					if (done.find(e[i].boss[j]) == done.end())
					{
						//cout << "check ";
						//cout << t << endl;
						check = 1;
						break;
					}
				}
				if (check == 0)
				{
					e[i].salary = 0;
					for (int j = 0; j < e[i].boss.size(); j++)
						e[i].salary += e[e[i].boss[j]].salary;
					//cout << " " << e[i].salary << endl;
					done.insert(i);
					count++;
					//cout << count << " "<< i << endl;
				}
			}
			if (i < relations.size())
				i++;
			else
			{
				i = 0;
			}
		}
		long res = 0;
		for (int k = 0; k < e.size(); ++k)
		{
			//cout << e[k].salary << " ";
			res += e[k].salary;
		}
		return res;
	}
};