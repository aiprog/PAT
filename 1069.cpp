#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void printVec (vector<int> &vec)
{
  for (auto &i : vec)
    printf ("%d", i);
}

int main ()
{
  vector<int> num (4);
  for (int i = 0; i < 4; ++i)
    scanf ("%1d", &num[i]);

  vector<int> bh = { 6, 1, 7, 4 }, zero = { 0, 0, 0, 0 };
  do
  {
    sort (num.rbegin (), num.rend ());
    vector<int> reNum (num.rbegin (), num.rend ());

    printVec (num);
    printf (" - ");
    printVec (reNum);
    printf (" = ");

    for (int i = 3; i != -1; --i)
    {
      if (num[i] < reNum[i])
      {
        num[i] += 10;
        --num[i - 1];
      }
      num[i] -= reNum[i];
    }

    printVec (num);
    printf ("\n");
  } while (num != bh && num != zero);

  return 0;
}