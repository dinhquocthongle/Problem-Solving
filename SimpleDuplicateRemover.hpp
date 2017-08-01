#include <stdio.h>
#include <vector>
using namespace std;

class SimpleDuplicateRemover
{
public:
	//the program goes through the sequence from the last to the first element
	//when it meets the number for the first time, it inserts that number into the result vector
	vector<int> process(vector<int> sequence)
	{
		vector<int> result;
		for (int i = sequence.size() -1; i >= 0;i--)
		{
			int check = 0;
			for(int j = 0; j < result.size(); j++)
				if (result[j] == sequence[i])
					check = 1;
			if (check == 0)
				result.insert(result.begin(), sequence[i]); 
		}
		return result;
	}
};