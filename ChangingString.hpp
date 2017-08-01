#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

class ChangingString
{
	public:
    //this function declares a distance int array and produce the distance of each pair of elements
    //then it sorts the array
    //a while loop goes through the array k times
    //if distance is 0, change it to 1, else change it to 0
    //the smallest distance is the sum of the array
	int distance(string a, string b, int k)
	{
		int l = a.length();
		vector<int> dis;
		for (int i = 0; i < l; i++) 
		{
			int d = abs((int)a[i] - (int)b[i]);
			dis.push_back(d);
		}
		for (int i = 0; i < l-1; i++) 
		{
			int min  = i;
			for (int j = i+1; j < l; j++) 
				if (dis[j] < dis[min])
					min = j;
			if (min != i)
			{
				int temp = dis[i];
				dis[i] = dis[min];
				dis[min] = temp;
			}
		}
		int count = l-1;
		while (k != 0) 
		{
			k--;
			if (dis[count] != 0) 
				dis[count] = 0;
			else
				dis[count] = 1;
			count--;
		}
		int sum = 0;
		for (int i = 0; i < l; i++) 
		{
			sum = sum + dis[i];
		}
		return sum;
	}
};
