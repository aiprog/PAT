#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int exitNum;
  scanf ("%d", &exitNum);

  vector<int> dist (exitNum);
  vector<int> sum (exitNum);

  for (int i = 0; i < exitNum; ++i)
  {
    scanf ("%d", &dist[i]);
    sum[i] = dist[i];
    if (i)
      sum[i] += sum[i - 1];
  }

  int reqNum;
  scanf ("%d", &reqNum);

  for (int i = 0; i < reqNum; ++i)
  {
    int exit1, exit2;
    scanf ("%d %d", &exit1, &exit2);

    --exit1;
    --exit2;
    if (exit1 > exit2)
      swap (exit1, exit2);

    int shortest = sum[exit2] - sum[exit1] + dist[exit1] - dist[exit2];
    if (sum[exitNum - 1] - shortest < shortest)
      shortest = sum[exitNum - 1] - shortest;

    printf ("%d\n", shortest);
  }

  return 0;
}