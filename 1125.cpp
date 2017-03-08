#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int segNum;
  scanf ("%d", &segNum);

  vector<double> seg (segNum);
  for (auto &i : seg)
    scanf ("%lf", &i);

  sort (seg.begin (), seg.end ());
  for (int i = 1; i < segNum; ++i)
    seg[i] = (seg[i] + seg[i - 1]) / 2;
  printf ("%d\n", (int)seg[segNum - 1]);

  return 0;
}