#include <cstdio>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

struct City
{
  bool visit;
  int cost[2];
  int parent;
};

struct Road
{
  int cost[2];
};

void printPath (stack<int> &path)
{
  bool first = true;
  while (!path.empty ())
  {
    if (!first)
      printf (" -> ");
    else
      first = false;

    printf ("%d", path.top ());
    path.pop ();
  }
  printf ("\n");
}

int main ()
{
  int cityNum, roadNum;
  scanf ("%d %d", &cityNum, &roadNum);

  vector<City> city (cityNum);
  vector<vector<Road>> road (cityNum);
  
  for (auto &i : road)
  {
    i.resize (cityNum);
    for (auto &j : i)
      j = { { 0, 0 } };
  }

  for (int i = 0; i < roadNum; ++i)
  {
    int roadA, roadB, oneWay, len, time;
    scanf ("%d %d %d %d %d", &roadA, &roadB, &oneWay, &len, &time);

    road[roadA][roadB] = { len, time };
    if (!oneWay)
      road[roadB][roadA] = { len, time };
  }

  int src, dst;
  scanf ("%d %d", &src, &dst);

  vector<stack<int>> path (2);
  vector<int> min (2);

  for (int i = 0; i < 2; ++i)
  {
    for (auto &j : city)
      j = { false, { INT_MAX, INT_MAX }, -1 };
    city[src] = { true, { 0, 0 }, -1 };

    int newAdd = src;
    while (newAdd != dst)
    {
      for (int j = 0; j < cityNum; ++j)
      {
        if (road[newAdd][j].cost[i] && !city[j].visit)
        {
          int newCost = city[newAdd].cost[i] + road[newAdd][j].cost[i];
          int addCost = city[newAdd].cost[1 - i] + road[newAdd][j].cost[1 - i];
          if (i)
            addCost = city[newAdd].cost[1 - i] + 1;

          if (newCost < city[j].cost[i] || (newCost == city[j].cost[i] && addCost < city[j].cost[1 - i]))
          {
            city[j].cost[i] = newCost;
            city[j].cost[1 - i] = addCost;
            city[j].parent = newAdd;
          }
        }
      }

      newAdd = -1;
      for (int j = 0; j < cityNum; ++j)
      {
        if (!city[j].visit && (newAdd == -1 || city[j].cost[i] < city[newAdd].cost[i]))
          newAdd = j;
      }
      city[newAdd].visit = true;
    }

    min[i] = city[dst].cost[i];
    for (int ite = dst; ite != -1; ite = city[ite].parent)
      path[i].push (ite);
  }

  if (path[0] == path[1])
  {
    printf ("Distance = %d; Time = %d: ", min[0], min[1]);
    printPath (path[0]);
  }
  else
  {
    printf ("Distance = %d: ", min[0]);
    printPath (path[0]);
    printf ("Time = %d: ", min[1]);
    printPath (path[1]);
  }

  return 0;
}