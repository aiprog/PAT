#include <cstdio>

struct City
{
  int visit = false;
  int lost = false;
};

void DFS (int **graph, City *info, int cityNum, int root)
{
  info[root].visit = true;
  for (int i = 1; i <= cityNum; ++i)
  {
    if (graph[root][i] && !info[i].visit && !info[i].lost)
      DFS (graph, info, cityNum, i);
  }
}

int main ()
{
  int cityNum, roadNum, lostNum;
  scanf ("%d %d %d", &cityNum, &roadNum, &lostNum);

  int **graph = new int*[cityNum + 1];
  for (int i = 0; i <= cityNum; ++i)
    graph[i] = new int[cityNum + 1] ();

  for (int i = 0; i < roadNum; ++i)
  {
    int cityA, cityB;
    scanf ("%d %d", &cityA, &cityB);
    graph[cityA][cityB] = graph[cityB][cityA] = 1;
  }

  City *info = new City[cityNum + 1];
  for (int i = 0; i < lostNum; ++i)
  {
    int lostCity;
    scanf ("%d", &lostCity);
    info[lostCity].lost = true;

    int component = 0;
    for (int i = 1; i <= cityNum; ++i)
    {
      if (!info[i].visit && !info[i].lost)
      {
        DFS (graph, info, cityNum, i);
        ++component;
      }
    }
    printf ("%d\n", component ? component - 1 : 0);

    for (int i = 0; i <= cityNum; ++i)
      info[i].visit = info[i].lost = false;
  }

  for (int i = 0; i <= cityNum; ++i)
    delete[] graph[i];
  delete[] graph;

  return 0;
}