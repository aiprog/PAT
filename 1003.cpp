#include <cstdio>
#include <cstring>
#include <climits>

typedef struct _node
{
  bool visit;
  int minWeight;
  int pathNum;
  int rescureNum;
} Node;

int main ()
{
  int city, road, src, dst;
  scanf ("%d %d %d %d", &city, &road, &src, &dst);

  int *rescure = new int[city];
  for (int i = 0; i < city; ++i)
    scanf ("%d", rescure + i);

  int **weight = new int *[city];
  for (int i = 0; i < city; ++i)
  {
    weight[i] = new int[city];
    memset (weight[i], 0, city * sizeof (int));
  }

  for (int i = 0; i < road; ++i)
  {
    int c1, c2, w;
    scanf ("%d %d %d", &c1, &c2, &w);

    weight[c1][c2] = weight[c2][c1] = w;
  }

  Node *info = new Node[city];
  for (int i = 0; i < city; ++i)
  {
    if (i == src)
    {
      info[i].visit = false;
      info[i].minWeight = 0;
      info[i].pathNum = 1;
      info[i].rescureNum = rescure[src];
    }
    else
    {
      info[i].visit = false;
      info[i].minWeight = INT_MAX;
      info[i].pathNum = 0;
      info[i].rescureNum = 0;
    }
  }

  int newAdd = src;
  while (newAdd != -1 && newAdd != dst)
  {
    info[newAdd].visit = true;
    for (int i = 0; i < city; ++i)
    {
      if (!info[i].visit && weight[newAdd][i])
      {
        int newWeight = info[newAdd].minWeight + weight[newAdd][i];
        if (newWeight < info[i].minWeight)
        {
          info[i].minWeight = newWeight;
          info[i].pathNum = info[newAdd].pathNum;
          info[i].rescureNum = info[newAdd].rescureNum + rescure[i];
        }
        else if (newWeight == info[i].minWeight)
        {
          info[i].pathNum += info[newAdd].pathNum;
          int newRescueNum = info[newAdd].rescureNum + rescure[i];
          if (newRescueNum > info[i].rescureNum)
            info[i].rescureNum = newRescueNum;
        }
      }
    }

    newAdd = -1;
    int minWeight = INT_MAX;
    for (int i = 0; i < city; ++i)
    {
      if (!info[i].visit && info[i].minWeight < minWeight)
      {
        newAdd = i;
        minWeight = info[i].minWeight;
      }
    }
  }

  printf ("%d %d\n", info[dst].pathNum, info[dst].rescureNum);

  delete[] rescure;
  for (int i = 0; i < city; ++i)
    delete[] weight[i];
  delete[] weight;
  delete[] info;

  return 0;
}
