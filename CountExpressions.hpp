#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class CountExpressions
{
public:
  int result;
  void cal(vector<int> d, vector<int> op, int v)
  {
    vector<int> temp_o = op;
    for (int j = 0; j < op.size(); j++)
    {
      vector<int> temp_d = d;
      for (int i = 0; i < 3; i++)
      {
        int tmp = temp_o[j] % 10;
        temp_o[j] /= 10;
        if (tmp == 1)
          temp_d[1] = temp_d[0] + temp_d[1];
        else if (tmp == 2)
          temp_d[1] = temp_d[0] - temp_d[1];
        else
          temp_d[1] = temp_d[0] * temp_d[1];
        temp_d.erase(temp_d.begin());
      }
      if (temp_d[0] == v)
        result++;
    }
  }
  int calcExpressions(int x, int y, int val)
  {
    result = 0;
    vector<int> op;
    for (int i = 1; i < 4; i++)
      for (int j = 1; j < 4; j++)
        for (int h = 1; h < 4; h++)
          op.push_back(i + j*10 + h*100);
    vector<int> num;
    num.push_back(x);
    num.push_back(y);
    num.push_back(x);
    for (int i =0; i < 2; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        vector<int> digits;
        digits.push_back(num[i]);
        for (int h = 0; h < 3; h++)
          if (h == j)
            digits.push_back(num[i]);
          else
            digits.push_back(num[i+1]);
        cal(digits, op, val);
      }
    }
    return result;
  }
};