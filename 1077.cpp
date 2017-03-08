#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main ()
{
  int num;
  char ch;
  scanf ("%d%c", &num, &ch);

  string strA;
  getline (cin, strA);
  --num;

  int cnt = 0;
  for (int i = 0; i < num; ++i)
  {
    string strB;
    getline (cin, strB);

    int iteA = (int)strA.size () - 1, iteB = (int)strB.size () - 1;
    while (iteA != cnt - 1 && iteB != -1 && strA[iteA] == strB[iteB])
    {
      --iteA;
      --iteB;
    }
    cnt = iteA + 1;
  }

  string common (strA.begin () + cnt, strA.end ());
  if (!common.empty ())
    cout << common << endl;
  else
    cout << "nai" << endl;

  return 0;
}