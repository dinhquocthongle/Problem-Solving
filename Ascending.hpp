#include <stdio.h>
#include <vector>
using namespace std;

class Ascending
{
	public:
	//the function gets the number of strides needed to turn around at first
	//then it goes through each flight and produces the sum of the strides
	int steps(vector<int> flights, int stairsPerStride)
	{
		int result = (flights.size()-1)*2;
		for (int i = 0; i < flights.size(); i++) 
		{
			result = result + flights[i]/stairsPerStride;
			if (flights[i] % stairsPerStride != 0)
				result++;
		}
		return result;
	}
};
