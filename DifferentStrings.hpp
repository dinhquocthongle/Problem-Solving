#include <stdio.h>
#include <vector>
#include <string>
#include <set>
using namespace std;

class DifferentStrings
{
public:
	int minimize(string A, string B)
	{
		int result = 100;
		for (int i = 0; i < (B.length() - A.length()+1); i++)
		{
			int check = 0;
			for (int j = 0; j < A.length(); j++)
				if (A[j] != B[i+j])
					check++;
			if (check < result)
				result = check;
		}
		return result;
	}
};