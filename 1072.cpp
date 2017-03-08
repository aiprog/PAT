#include <cstdio>
#include <cfloat>
#include <vector>

using namespace std;

struct Node
{
  double dist;
  bool visit;
};

int readPlace (int houseNum)
{
  char buf[10];
  scanf ("%s", buf);

  int place;
  if (buf[0] != 'G')
    sscanf (buf, "%d", &place);
  else
  {
    sscanf (buf + 1, "%d", &place);
    place += houseNum;
  }

  return place;
}

int main ()
{
  int houseNum, stationNum, roadNum, nodeNum, serviceRange;
  scanf ("%d %d %d %d", &houseNum, &stationNum, &roadNum, &serviceRange);
  nodeNum = houseNum + stationNum;

  vector<vector<double>> road (nodeNum + 1);
  for (auto &i : road)
    i.resize (road.size ());

  for (int i = 0; i < roadNum; ++i)
  {
    int placeA = readPlace (houseNum), placeB = readPlace (houseNum);
    double dist;

    scanf ("%lf", &dist);
    road[placeA][placeB] = road[placeB][placeA] = dist;
  }

  vector<Node> arr (nodeNum + 1);
  int station = -1;
  double min = 0, average = 0;

  for (int newStation = houseNum + 1; newStation <= nodeNum; ++newStation)
  {
    for (auto &i : arr)
      i = Node { DBL_MAX, false };
    arr[newStation].dist = 0;
    arr[newStation].visit = true;

    int newAdd = newStation;
    while (1)
    {
      for (int dst = 1; dst <= nodeNum; ++dst)
      {
        if (road[newAdd][dst] && !arr[dst].visit)
        {
          double newDist = arr[newAdd].dist + road[newAdd][dst];
          if (newDist < arr[dst].dist)
            arr[dst].dist = newDist;
        }
      }

      newAdd = -1;
      for (int i = 1; i <= nodeNum; ++i)
      {
        if (arr[i].dist != DBL_MAX && !arr[i].visit)
        {
          if (newAdd == -1 || arr[i].dist < arr[newAdd].dist)
            newAdd = i;
        }
      }

      if (newAdd != -1)
        arr[newAdd].visit = true;
      else
        break;
    }

    double newMin = -1, newAverage = 0;
    for (int i = 1; i <= houseNum; ++i)
    {
      if (arr[i].visit && arr[i].dist <= serviceRange)
      {
        if (newMin == -1 || arr[i].dist < newMin)
          newMin = arr[i].dist;
        newAverage += arr[i].dist;
      }
      else
      {
        newMin = -1;
        break;
      }
    }

    if (newMin != -1)
    {
      newAverage /= houseNum;
      if (station == -1 || ((newMin > min) || (newMin == min && newAverage < average)))
      {
        station = newStation;
        min = newMin;
        average = newAverage;
      }
    }
  }

  if (station != -1)
    printf ("G%d\n%.1lf %.1lf\n", station - houseNum, min, average);
  else
    printf ("No Solution\n");

  return 0;
}