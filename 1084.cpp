#include <cstdio>
#include <cctype>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
  string type, show;
  cin >> type >> show;
  show.resize (type.size ());

  vector<int> flag (256);
  auto iteA = type.begin (), iteB = show.begin ();

  while (iteA != type.end ())
  {
    char chA = *iteA, chB = *iteB;
    chA = (char)toupper (chA);
    chB = (char)toupper (chB);

    if (chA != chB)
    {
      if (!flag[chA])
      {
        printf ("%c", chA);
        flag[chA] = 1;
      }
    }
    else
      ++iteB;

    ++iteA;
  }
  printf ("\n");

  return 0;
}