#include <cstdio>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void findBest (vector<pair<int, int>> &arr, int beg, int num, int rem, vector<int> &tmp, vector<int> &best)
{
  if (!num && !rem)
  {
    if (best.empty ())
      best = tmp;
    else
    {
      int bestSum = accumulate (best.begin (), best.end (), 0);
      int tmpSum = accumulate (tmp.begin (), tmp.end (), 0);

      if (tmpSum > bestSum)
        best = tmp;
      else if (tmpSum == bestSum)
      {
        int iteT = (int)tmp.size () - 1, iteB = (int)best.size () - 1;
        while (iteT != -1 && iteB != -1)
        {
          if (tmp[iteT] != best[iteB])
          {
            if (tmp[iteT] > best[iteB])
              best = tmp;
            break;
          }

          --iteT;
          --iteB;
        }
      }
    }
  }
  else if (beg != arr.size () && num && num * arr[beg].second <= rem)
  {
    findBest (arr, beg + 1, num, rem, tmp, best);

    int numTmp = num;
    for (int i = 0; i < numTmp; ++i)
    {
      tmp.push_back (arr[beg].first);
      --num;
      rem -= arr[beg].second;
      findBest (arr, beg + 1, num, rem, tmp, best);
    }

    for (int i = 0; i < numTmp; ++i)
      tmp.pop_back ();
  }
}

int main ()
{
  int val, num, power;
  scanf ("%d %d %d", &val, &num, &power);

  int max = (int)pow (val, 1.0 / power);
  vector<pair<int, int>> arr (max + 1);

  for (int i = 1; i <= max; ++i)
    arr[i] = { i, (int)pow (i, power) };

  vector<int> best, tmp;
  findBest (arr, 1, num, val, tmp, best);

  if (!best.empty ())
  {
    printf ("%d = ", val);
    for (int i = num - 1; i != -1; --i)
    {
      if (i != num - 1)
        printf (" + ");
      printf ("%d^%d", best[i], power);
    }
    printf ("\n");
  }
  else
    printf ("Impossible\n");

  return 0;
}