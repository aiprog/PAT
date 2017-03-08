#include <cstdio>
#include <list>
#include <vector>
#include <queue>

using namespace std;

int main ()
{
  int userNum, level;
  scanf ("%d %d", &userNum, &level);

  vector<list<int>> relation (userNum + 1);
  for (int i = 1; i <= userNum; ++i)
  {
    int followNum;
    scanf ("%d", &followNum);

    for (int j = 0; j < followNum; ++j)
    {
      int follow;
      scanf ("%d", &follow);
      relation[follow].push_back (i);
    }
  }

  int reqNum;
  scanf ("%d", &reqNum);

  for (int i = 0; i < reqNum; ++i)
  {
    int src;
    scanf ("%d", &src);

    vector<int> visit (userNum + 1);
    queue<pair<int, int>> que;
    int cnt = 0;

    que.push ({ src, 1 });
    while (!que.empty ())
    {
      auto next = que.front ();
      que.pop ();

      if (!visit[next.first])
      {
        visit[next.first] = true;
        if (next.second >= 2 && next.second <= level + 1)
          ++cnt;

        if (next.second <= level)
        {
          for (auto &j : relation[next.first])
          {
            if (!visit[j])
              que.push ({ j, next.second + 1 });
          }
        }
      }
    }

    printf ("%d\n", cnt);
  }

  return 0;
}