#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
  vector<int> arr (256);
  string owner, eva;

  cin >> owner >> eva;
  for (auto &i : owner)
    ++arr[i];

  for (auto &i : eva)
    --arr[i];

  int cnt = 0;
  for (auto &i : arr)
  {
    if (i < 0)
      cnt += i;
  }

  if (cnt >= 0)
    printf ("Yes %llu\n", owner.size () - eva.size ());
  else
    printf ("No %d\n", -cnt);

  return 0;
}