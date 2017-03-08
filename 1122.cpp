#include <cstdio>
#include <vector>

using namespace std;

void removeLine ()
{
  char buf[10000];
  scanf ("%[^\n]%c", buf, buf);
}

int main ()
{
  int nodeNum, roadNum;
  scanf ("%d %d", &nodeNum, &roadNum);

  vector<vector<int>> graph (nodeNum + 1);
  for (auto &i : graph)
    i.resize (nodeNum + 1);

  for (int i = 0; i < roadNum; ++i)
  {
    int nodeA, nodeB;
    scanf ("%d %d", &nodeA, &nodeB);

    graph[nodeA][nodeB] = 1;
    graph[nodeB][nodeA] = 1;
  }

  int reqNum;
  scanf ("%d", &reqNum);

  for (int i = 0; i < reqNum; ++i)
  {
    int nodeCnt;
    scanf ("%d", &nodeCnt);

    if (nodeCnt != nodeNum + 1)
    {
      printf ("NO\n");
      removeLine ();
    }
    else
    {
      vector<int> path (nodeNum + 1);
      vector<int> cnt (nodeNum + 1);

      for (auto &j : path)
      {
        scanf ("%d", &j);
        cnt[j]++;
      }

      if (path[0] != path[nodeNum])
        printf ("NO\n");
      else
      {
        int j;
        for (j = 1; j <= nodeNum; ++j)
        {
          if (cnt[j] < 1 || cnt[j] > 2 || (cnt[j] == 2 && j != path[0]))
            break;
        }

        if (j != nodeNum + 1)
          printf ("NO\n");
        else
        {
          int k;
          for (k = 1; k <= nodeNum; ++k)
          {
            if (!graph[path[k]][path[k - 1]])
              break;
          }

          if (k != nodeNum + 1)
            printf ("NO\n");
          else
            printf ("YES\n");
        }
      }
    }
  }

  return 0;
}