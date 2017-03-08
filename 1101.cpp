#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main ()
{
  int num;
  scanf ("%d", &num);

  vector<int> arr (num);
  for (auto &i : arr)
    scanf ("%d", &i);

  set<int> left, right;
  for (auto &i : arr)
    right.insert (i);

  vector<int> pivot;
  for (auto &i : arr)
  {
    right.erase (i);
    if (!left.empty ())
    {
      auto max = left.end ();
      --max;

      if (*max > i)
      {
        left.insert (i);
        continue;
      }
    }

    if (right.empty () || *right.begin () > i)
      pivot.push_back (i);
    left.insert (i);
  }

  sort (pivot.begin (), pivot.end ());
  printf ("%llu\n", pivot.size ());

  bool first = true;
  for (auto &i : pivot)
  {
    if (first)
      first = false;
    else
      printf (" ");
    printf ("%d", i);
  }
  printf ("\n");

  return 0;
}