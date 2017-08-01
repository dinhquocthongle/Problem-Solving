#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class ForestGarbage
{
public:
  int x_start, y_start, x_end, y_end;
  int price[50][50];
  vector<string> f;
  void find_path( int x, int y, int pre_x, int pre_y)
  {
    if ((x == x_end) and (y == y_end))
      return;
    if ((x-1 >= 0) and (x-1 != pre_x))
    {
      int tmp_cost = price[x][y];
      if (f[x-1][y] == 'x')
        tmp_cost++;
      else if (f[x-1][y] == 'g')
        tmp_cost += 2500;
      if ((price[x-1][y] > tmp_cost) or (price[x-1][y] == -1))
      {
        price[x-1][y] = tmp_cost;
        find_path(x-1, y, x, y);
      }
    }
    if ((x+1 < f.size()) and (x+1 != pre_x))
    {
      int tmp_cost = price[x][y];
      if (f[x+1][y] == 'x')
        tmp_cost++;
      else if (f[x+1][y] == 'g')
        tmp_cost += 2500;
      if ((price[x+1][y] > tmp_cost) or (price[x+1][y] == -1))
      {
        price[x+1][y] = tmp_cost;
        find_path(x+1, y, x, y);
      }
    }
    if ((y-1 >= 0) and (y-1 != pre_y))
    {
      int tmp_cost = price[x][y];
      if (f[x][y-1] == 'x')
        tmp_cost++;
      else if (f[x][y-1] == 'g')
        tmp_cost += 2500;
      if ((price[x][y-1] > tmp_cost) or (price[x][y-1] == -1))
      {
        price[x][y-1] = tmp_cost;
        find_path(x, y-1, x, y);
      }
    }
    if ((y+1 < f[0].length()) and (y+1 != pre_y))
    {
      int tmp_cost = price[x][y];
      if (f[x][y+1] == 'x')
        tmp_cost++;
      else if (f[x][y+1] == 'g')
        tmp_cost += 2500;
      if ((price[x][y+1] > tmp_cost) or (price[x][y+1] == -1))
      {
        price[x][y+1] = tmp_cost;
        find_path(x, y+1, x, y);
      }
    }
  }
  vector<int> bestWay(vector<string> forest)
  {
    vector<int> result;
    for (int i = 0; i < 50; i++)
      for (int j = 0; j < 50; j++)
        price[i][j] = -1;

    for (int x = 0; x < forest.size(); x++)
      for (int y = 0; y < forest[x].length(); y++)
      {
        if (forest[x][y] == 'S')
        {
          x_start = x;
          y_start = y;
          price[x][y] = 0;
        }
        else if (forest[x][y] == 'F')
        {
          x_end = x;
          y_end = y;
        }
        else if (forest[x][y] == 'g')
        {
          if (x-1 >= 0)
            if (forest[x-1][y] == '.')
              forest[x-1][y] = 'x';
          if (x+1 < forest.size())
            if (forest[x+1][y] == '.')
              forest[x+1][y] = 'x';
          if (y-1 >= 0)
            if (forest[x][y-1] == '.')
              forest[x][y-1] = 'x';
          if (y+1 < forest[x].length())
            if (forest[x][y+1] == '.')
              forest[x][y+1] = 'x';
        }
      }
    for (int i = 0; i < forest.size(); i++)
    {
      string tmp;
      for (int j = 0; j < forest[i].length(); j++)
      {
        tmp += forest[i][j];
        cout << forest[i][j] << " ";
      }
      cout << endl;
      f.push_back(tmp);
    }
    find_path(x_start, y_start,-100, -100);
    cout << endl;
    for (int i = 0; i < forest.size(); i++)
    {
      for (int j = 0; j < forest[i].length(); j++)
        cout << price[i][j] << "  ";
      cout << endl;
    }
    result.push_back(price[x_end][y_end]/2500);
    result.push_back(price[x_end][y_end]%2500);
    cout << result[0];
    cout << result[1];
    return result;
  }
};