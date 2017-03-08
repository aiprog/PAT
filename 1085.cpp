#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int num, p;
  scanf ("%d %d", &num, &p);

  vector<int> ivec (num);
  for (int i = 0; i < num; ++i)
    scanf ("%d", &ivec[i]);
  sort (ivec.begin (), ivec.end ());

  int beg = 0, end = 0, len = 1;
  while (1)
  {
    ++end;
    if (end == num)
    {
      if (end - beg > len)
        len = end - beg;

      break;
    }

    if (ivec[end] > (long long)ivec[beg] * p)
    {
      if (end - beg > len)
        len = end - beg;

      ++beg;
    }
  }
  printf ("%d\n", len);

  return 0;
}