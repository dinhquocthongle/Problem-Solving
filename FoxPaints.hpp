#include <stdio.h>
#include <vector>
using namespace std;

class FoxPaints
{
public:
	long long maxSpace(int w, int h, long long M)
	{
		long long result = 0;
		if ((w*h <= M) and (w*h > 0))
			return w*h;
		int tmp1, tmp2;
		if (w < h)
		{
			tmp1 = w;
			tmp2 = h;
		}
		else
		{
			tmp2 = w;
			tmp1 = h;
		}
		long long di = 100000000;
		for (int i = tmp1; i > 0; i--)
		{
			int check = M/i;
			if ((check <= tmp2) and (check > 0))
			{
				if (di > M%i)
				{
					di = M%i;
				}
			}
		}
		result = M - di;
		return result;
	}
};