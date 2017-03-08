#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int valNum;
  scanf ("%d", &valNum);

  vector<int> val (valNum);
  for (auto &i : val)
    scanf ("%d", &i);
  sort (val.begin (), val.end ());

  int i;
  for (i = valNum; i != 0; --i)
  {
    auto valCmp = [=](int key, int val) { return key < val; };
    auto ite = upper_bound (val.begin (), val.end (), i, valCmp);

    if (ite != val.end () && (val.end () - ite) >= i)
      break;
  }
  printf ("%d\n", i);

  return 0;
}