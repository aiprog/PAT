#include <cstdio>
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

struct City
{
  bool visit;
  int fun;
  int cost;
  int totalFun;
  int cityNum;
  int roadNum;
  vector<int> prev;
};

int str2Int (const string &str)
{
  return (str[0] - 'A') * 26 * 26 + (str[1] - 'A') * 26 + (str[2] - 'A');
}

int mapStr (vector<int> &int2Index, vector<int> &index2Int, int &index, const string &str)
{
  int num = str2Int (str);
  if (int2Index[num] == -1)
  {
    int2Index[num] = index;
    index2Int[index] = num;

    return index++;
  }
  else
    return int2Index[num];
}

int main ()
{
  int cityNum, roadNum;
  scanf ("%d %d", &cityNum, &roadNum);

  vector<int> int2Index (26 * 26 * 26, -1);
  vector<int> index2Int (cityNum, -1);

  string strSrc;
  int index = 0;

  cin >> strSrc;
  mapStr (int2Index, index2Int, index, strSrc);

  vector<City> city (cityNum);
  for (int i = 1; i < cityNum; ++i)
  {
    string str;
    cin >> str;

    int ID = mapStr (int2Index, index2Int, index, str);
    city[ID].visit = false;
    scanf ("%d", &city[ID].fun);
  }

  vector<vector<int>> road (cityNum);
  for (auto &i : road)
    i.resize (cityNum);

  for (int i = 0; i < roadNum; ++i)
  {
    string cityA, cityB;
    cin >> cityA >> cityB;

    int IDA = mapStr (int2Index, index2Int, index, cityA);
    int IDB = mapStr (int2Index, index2Int, index, cityB);

    int cost;
    scanf ("%d", &cost);
    road[IDA][IDB] = road[IDB][IDA] = cost;
  }

  city[0] = City { true, 0, 0, 0, 0, 1 };
  city[0].prev.push_back (-1);

  int dst = mapStr (int2Index, index2Int, index, string ("ROM"));
  for (int newAdd = 0; newAdd != dst;)
  {
    for (int i = 0; i < cityNum; ++i)
    {
      if (road[newAdd][i])
      {
        int newCost = city[newAdd].cost + road[newAdd][i];
        if (city[i].prev.empty () || newCost < city[i].cost)
        {
          city[i].cost = newCost;
          city[i].prev.clear ();
          city[i].prev.push_back (newAdd);
        }
        else if (newCost == city[i].cost)
          city[i].prev.push_back (newAdd);
      }
    }

    int next = -1;
    for (int i = 0; i < cityNum; ++i)
    {
      if (!city[i].visit && !city[i].prev.empty ())
      {
        if (next == -1 || city[i].cost < city[next].cost)
          next = i;
      }
    }

    auto &prev = city[next].prev;
    int best = -1;

    city[next].roadNum = 0;
    for (int i = 0; i < prev.size (); ++i)
    {
      int newTotalFun = city[prev[i]].totalFun + city[next].fun;
      int newCityNum = city[prev[i]].cityNum + 1;

      if (best == -1 || newTotalFun > city[next].totalFun ||
        (newTotalFun == city[next].totalFun && newCityNum < city[next].cityNum))
      {
        best = prev[i];
        city[next].totalFun = newTotalFun;  
        city[next].cityNum = newCityNum;
      }

      city[next].roadNum += city[prev[i]].roadNum;
    }

    city[next].visit = true;
    city[next].prev.clear ();
    city[next].prev.push_back (best);

    newAdd = next;
  }

  list<string> path;
  path.push_front ("ROM");

  for (int ite = city[dst].prev[0]; ite != -1; ite = city[ite].prev[0])
  {
    int num = index2Int[ite];
    string name;

    name.push_back ((char)('A' + num / (26 * 26)));
    name.push_back ((char)('A' + num / 26 % 26));
    name.push_back ((char)('A' + num % 26));

    path.push_front ("->");
    path.push_front (name);
  }

  printf ("%d %d ", city[dst].roadNum, city[dst].cost);
  printf ("%d %d\n", city[dst].totalFun, city[dst].totalFun / city[dst].cityNum);
  for (auto &i : path)
    cout << i;
  printf ("\n");

  return 0;
}