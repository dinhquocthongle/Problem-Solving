#include <stdio.h>
#include <string.h>
using namespace std;

class StrangeComputer
{
	public:
	//this function scan the string
	//for every time the string changes from 0 to 1 and from 1 to 0, the count increases by 1
	int setMemory(string mem)
	{
		int count = 0;
		char state = '0';
		for(int i = 0; i < mem.length(); i++)
		{
			if (state != mem[i])
			{
				count++;
				state = mem[i];
			}
		}
		return count;
	}
};