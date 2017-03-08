#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
  int repeatTime;
  scanf ("%d", &repeatTime);

  string str;
  cin >> str;

  vector<int> stuck (256, 1);
  for (int ite = 0; ite != (int)str.size ();)
  {
    int ch = str[ite], cnt = 0;
    while (ite != (int)str.size () && str[ite] == ch)
    {
      ++ite;
      ++cnt;
    }

    if (cnt % repeatTime)
      stuck[ch] = 0;
  }

  vector<int> stuckTmp (stuck);
  for (auto &i : str)
  {
    if (stuckTmp[i])
    {
      printf ("%c", i);
      stuckTmp[i] = 0;
    }
  }
  printf ("\n");

  for (int ite = 0; ite != (int)str.size ();)
  {
    char ch = str[ite];
    printf ("%c", ch);

    if (stuck[ch])
      ite += repeatTime;
    else
      ++ite;
  }
  printf ("\n");

  return 0;
}