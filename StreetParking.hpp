#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class StreetParking
{
    public:
    //declare a vector of int with all 1s which length = length of street
    //check if there are Bs, Ds, Ss on the street
    //if it's, change the relevant elements in int's vector to 0
    //count the number of 1s which is the result
    int freeParks(string street)
    {
        vector<int> marks;
        for (int i = 0; i < street.length(); i++)
        {
            int n = 1;
            marks.push_back(n);
        }
        for (int i = 0; i < street.length();i++)
        {
            if (street[i] == 'B')
            {
                marks[i] = 0;
                if ((i-1) >= 0)
                    marks[i-1] = 0;
                if ((i-2) >= 0)
                    marks[i-2] = 0;
            }
            else if (street[i] == 'S')
            {
                marks[i] = 0;
                if ((i-1) >= 0)
                    marks[i-1] = 0;
                if ((i+1) < street.length())
                marks[i+1] = 0;
            }
            else if (street[i] == 'D')
            {
                marks[i] = 0;
            }
        }
        int res = 0;
        for (int i = 0; i < street.length(); i++)
        {
            if (marks[i] == 1)
                res++;
        }
        return res;
    }
};