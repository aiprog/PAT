#include <cstdio>
#include <vector>
#include <stack>
#include <climits>

struct Road
{
  int distance = -1;
  int cost;
};

struct City
{
  int distance = INT_MAX;
  int cost = INT_MAX;
  bool visit = false;
  int parent = -1;
};

int main ()
{
  int cityNum, roadNum, src, dst;
  scanf ("%d %d %d %d", &cityNum, &roadNum, &src, &dst);

  std::vector<City> city (cityNum);
  city[src].distance = 0;
  city[src].cost = 0;
  city[src].visit = true;

  std::vector<std::vector<Road>> graph (cityNum);
  for (auto &i : graph)
    i.resize (cityNum);

  for (int i = 0; i < roadNum; ++i)
  {
    int src, dst, distance, cost;
    scanf ("%d %d %d %d", &src, &dst, &distance, &cost);
    graph[src][dst].distance = graph[dst][src].distance = distance;
    graph[src][dst].cost = graph[dst][src].cost = cost;
  }

  int newAdd = src;
  while (newAdd != dst)
  {
    for (int i = 0; i < cityNum; ++i)
    {
      if (graph[newAdd][i].distance != -1 && !city[i].visit)
      {
        int newDistance = city[newAdd].distance + graph[newAdd][i].distance;
        int newCost = city[newAdd].cost + graph[newAdd][i].cost;

        if (newDistance < city[i].distance || (newDistance == city[i].distance && newCost < city[i].cost))
        {
          city[i].distance = newDistance;
          city[i].cost = newCost;
          city[i].parent = newAdd;
        }
      }
    }

    int next = -1;
    for (int i = 0; i < cityNum; ++i)
    {
      int newDistance = city[i].distance, newCost = city[i].cost;
      if (!city[i].visit && (next == -1 || newDistance < city[next].distance || (newDistance == city[next].distance &&
        newCost < city[next].cost)))
        next = i;
    }

    newAdd = next;
    city[newAdd].visit = true;
  }

  std::stack<int> path;
  int parent = dst;
  do
  {
    path.push (parent);
    parent = city[parent].parent;
  } while (parent != -1);

  while (!path.empty ())
  {
    printf ("%d ", path.top ());
    path.pop ();
  }
  printf ("%d %d\n", city[dst].distance, city[dst].cost);
  
  return 0;
}