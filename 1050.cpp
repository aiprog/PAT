#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
  string s1, s2;
  getline (cin, s1);
  getline (cin, s2);

  vector<int> flag (128);
  for (auto &i : s2)
    flag[i] = 1;

  for (auto &i : s1)
  {
    if (!flag[i])
      printf ("%c", i);
  }
  printf ("\n");

  return 0;
}