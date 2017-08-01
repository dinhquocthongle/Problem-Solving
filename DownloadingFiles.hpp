#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;
 
 
class DownloadingFiles
{
	public:
	struct file 
	{
		double speed;
		double time;
    };
    //from the idea of calculate final mark
    //the function below get the time and the speed
    //then set up new times when all the speed is 1
    //so that the contribution of each file is equally
    //from there, the program calculate the average time of downloading file which is the result
	double actualTime(vector<string> tasks)
	{
        //get input
        int length = tasks.size();
        vector<file> f;
        file t;
        t.speed = 0.0;
        t.time = 0.0;
        for (int i = 0; i < length; i++)
        {
            int check = 0;
            f.push_back(t);
            for (int j = 0; j < tasks[i].length(); j++)
            {
                if (check == 1)
                {
                    if ((tasks[i][j] >= '0') and (tasks[i][j] <= '9'))
                    {
                        f[i].time = f[i].time*10 + double(tasks[i][j])-48.0;
                    }
                }
                else
                {
                    if((tasks[i][j] >= '0') and (tasks[i][j] <= '9'))
                    {
                        f[i].speed = f[i].speed*10 + double(tasks[i][j])-48;
                    }
                    else if (tasks[i][j] == ' ')
                    {
                        check = 1;
                    }
                }
            }
        }
        //produce result
        double total_speed = 0.0;
        double total_time = 0.0;
        for (int i = 0; i < length; i++)
        {
            total_time = total_time + f[i].time*f[i].speed;
            total_speed = total_speed + f[i].speed;
        }
        double result = total_time/total_speed;
        return result;
	}
};
