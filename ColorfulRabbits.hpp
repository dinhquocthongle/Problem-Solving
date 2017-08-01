#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class ColorfulRabbits
{
public:
  struct color
  {
    int num_of_see;
    int count;
  };
  int getMinimum(vector<int> replies)
  {
    vector<color> comb;
    for (int i = 0; i < replies.size(); i++)
    {
      int check = 0;
      for (int j = 0; j < comb.size(); j++)
        if (comb[j].num_of_see == replies[i])
        {
          check = 1;
          comb[j].count++;
          break;
        }
      if (check == 0)
      {
        color tmp;
        tmp.num_of_see = replies[i];
        tmp.count = 1;
        comb.push_back(tmp);
      }
    }
    int result = 0;
    for (int i = 0; i < comb.size(); i++)
    {
      if (comb[i].count % (comb[i].num_of_see +1) != 0)
        result = result +  (comb[i].num_of_see +1)*(comb[i].count / (comb[i].num_of_see +1)) + (comb[i].num_of_see +1);
      else
        result = result + comb[i].count;
    }
    return result;
  }
};