#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

class UnsealTheSafe
{
public:
	long save[31][10];
	long find(int digit,int n)
	{
		long r = 0;
		if (n == 1)
			return 1;
		if (save[n][digit] != -1)
			return save[n][digit];
		if (digit == 1)
		{
			r += find(2, n-1);
			r += find(4, n-1);
		}
		else if (digit == 2)
		{
			r += find(1, n-1);
			r += find(3, n-1);
			r += find(5, n-1);
		}
		else if (digit == 3)
		{
			r += find(2, n-1);
			r += find(6, n-1);
		}
		else if (digit == 4)
		{
			r += find(1, n-1);
			r += find(7, n-1);
			r += find(5, n-1);
		}
		else if (digit == 5)
		{
			r += find(2, n-1);
			r += find(4, n-1);
			r += find(6, n-1);
			r += find(8, n-1);
		}
		else if (digit == 6)
		{
			r += find(3, n-1);
			r += find(5, n-1);
			r += find(9, n-1);
		}
		else if (digit == 7)
		{
			r += find(4, n-1);
			r += find(8, n-1);
			r += find(0, n-1);
		}
		else if (digit == 8)
		{
			r += find(5, n-1);
			r += find(7, n-1);
			r += find(9, n-1);
		}
		else if (digit == 9)
		{
			r += find(6, n-1);
			r += find(8, n-1);
		}
		else if (digit == 0)
		{
			r += find(7, n-1);
		}
		save[n][digit] = r;
		return r;
	}
	long countPasswords(int n) 
	{
		long long res = 0;
		for (int i = 0; i < 31; i++)
			for (int j = 0; j < 10; j++)
				save[i][j] = -1;
		for (int i = 0; i < 10; i++)
		{
			res += find(i, n);
		}
		return res;
	}
};