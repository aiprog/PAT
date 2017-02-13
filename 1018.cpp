#include <cstdio>
#include <vector>
#include <climits>

struct Station
{
  bool visit = false;
  int bikeNum;
  std::vector<int> parent;
  int pathLen = INT_MAX;
};

struct Path
{
  std::vector<int> path;
  int bikeSend = 0;
  int bikeRecv = 0;
};

void findOptimal (std::vector<Station> &station, int capacity, int src, Path &cur, Path &optimal)
{
  if (src == 0)
  {
    int bikeSend = 0, bikeRecv = 0;
    for (auto ite = cur.path.rbegin (); ite != cur.path.rend (); ++ite)
    {
      int bikeAvailable = bikeRecv + station[*ite].bikeNum;
      if (bikeAvailable >= capacity / 2)
        bikeRecv = bikeAvailable - capacity / 2;
      else
      {
        bikeSend += capacity / 2 - bikeAvailable;
        bikeRecv = 0;
      }
    }

    cur.bikeSend = bikeSend;
    cur.bikeRecv = bikeRecv;

    if (optimal.path.empty () || cur.bikeSend < optimal.bikeSend ||
        (cur.bikeSend == optimal.bikeSend && cur.bikeRecv < optimal.bikeRecv))
    {
      optimal.path = cur.path;
      optimal.path.push_back (src);
      optimal.bikeSend = cur.bikeSend;
      optimal.bikeRecv = cur.bikeRecv;
    }
  }
  else
  {
    station[src].visit = true;
    cur.path.push_back (src);

    for (auto i : station[src].parent)
      findOptimal (station, capacity, i, cur, optimal);

    station[src].visit = false;
    cur.path.pop_back ();
  }
}

int main ()
{
  int capacity, stationNum, dstStation, roadNum;
  scanf ("%d %d %d %d", &capacity, &stationNum, &dstStation, &roadNum);
  ++stationNum;

  std::vector<Station> station (stationNum);
  for (int i = 1; i < stationNum; ++i)
    scanf ("%d", &station[i].bikeNum);

  std::vector<std::vector<int>> graph (stationNum);
  for (auto &i : graph)
    i.resize (stationNum);

  for (int i = 0; i < roadNum; ++i)
  {
    int src, dst, cost;
    scanf ("%d %d %d", &src, &dst, &cost);
    graph[src][dst] = graph[dst][src] = cost;
  }

  station[0].visit = true;
  station[0].pathLen = 0;

  int newAdd = 0;
  while (newAdd != -1 && newAdd != dstStation)
  {
    station[newAdd].visit = true;

    for (int i = 1; i < stationNum; ++i)
    {
      if (graph[newAdd][i] && !station[i].visit)
      {
        int newLen = station[newAdd].pathLen + graph[newAdd][i];
        if (newLen < station[i].pathLen)
        {
          station[i].parent.clear ();
          station[i].parent.push_back (newAdd);
          station[i].pathLen = newLen;
        }
        else if (newLen == station[i].pathLen)
          station[i].parent.push_back (newAdd);
      }
    }

    int minCity = -1;
    for (int i = 1; i < stationNum; ++i)
    {
      if (!station[i].visit)
      {
        if (minCity == -1 || station[i].pathLen < station[minCity].pathLen)
          minCity = i;
      }
    }

    newAdd = minCity;
  }

  for (auto &i : station)
    i.visit = false;

  Path cur, optimal;
  findOptimal (station, capacity, dstStation, cur, optimal);

  printf ("%d ", optimal.bikeSend);
  for (auto ite = optimal.path.rbegin (); ite != optimal.path.rend (); ++ite)
  {
    printf ("%d", *ite);
    if (*ite != dstStation)
      printf ("->");
  }
  printf (" %d\n", optimal.bikeRecv);

  return 0;
}