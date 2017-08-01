#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class LotteryTicket
{
public:
	int result;
	void process(int p, vector<int> n)
	{
		if (p == 0)
		{
			result = 1;
			return;
		}
		if ((result == 1) or (n.size() == 0) or (p < 0))
			return;
		for (int i = 0; i < n.size(); i++)
		{
			vector<int> note_temp = n;
			note_temp.erase(note_temp.begin()+i);
			process(p - n[i], note_temp);
		}
	}

	string buy(int price, int b1, int b2, int b3, int b4)
	{
		result = 0;
		vector<int> note;
		note.push_back(b1);
		note.push_back(b2);
		note.push_back(b3);
		note.push_back(b4);
		if (b1+b2+b3+b4 < price)
			return "IMPOSSIBLE";
		for (int i = 0; i < 4; i++)
		{
			vector<int> note_temp = note;
			note_temp.erase(note_temp.begin()+i);
			process(price - note[i], note_temp);
		}
		if (result == 1)
			return "POSSIBLE";
		return "IMPOSSIBLE";
	}
};