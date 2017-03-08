#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main ()
{
  int setNum;
  scanf ("%d", &setNum);

  vector<set<int>> sets (setNum);
  for (int i = 0; i < setNum; ++i)
  {
    int eleNum;
    scanf ("%d", &eleNum);

    for (int j = 0; j < eleNum; ++j)
    {
      int ele;
      scanf ("%d", &ele);
      sets[i].insert (ele);
    }
  }

  int reqNum;
  scanf ("%d", &reqNum);

  for (int i = 0; i < reqNum; ++i)
  {
    int setA, setB;
    scanf ("%d %d", &setA, &setB);

    --setA; --setB;
    if (sets[setA].size () > sets[setB].size ())
      swap (setA, setB);

    int share = 0, distinct = (int)(sets[setA].size () + sets[setB].size ());
    for (auto &i : sets[setA])
    {
      if (sets[setB].find (i) != sets[setB].end ())
      {
        ++share;
        --distinct;
      }
    }
    printf ("%.1lf%%\n", 1.0 * share / distinct * 100);
  }

  return 0;
}