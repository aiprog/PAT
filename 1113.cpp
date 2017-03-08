#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

vector<int>::iterator partition (vector<int>::iterator beg, vector<int>::iterator end, int pos)
{
  if (beg + 1 == end)
    return beg;
  else
  {
    int pivot = *beg;
    auto begIte = beg, endIte = end - 1;

    while (begIte < endIte)
    {
      while (begIte < endIte && *endIte > pivot)
        --endIte;

      if (begIte < endIte)
        *begIte++ = *endIte;

      while (begIte < endIte && *begIte < pivot)
        ++begIte;

      if (begIte < endIte)
        *endIte-- = *begIte;
    }
    *begIte = pivot;

    int ptr = (int)(begIte - beg);
    if (ptr < pos)
      return partition (begIte + 1, end, pos - ptr - 1);
    else if (ptr == pos)
      return begIte;
    else
      return partition (beg, begIte, pos);
  }
}

int main ()
{
  int valNum;
  scanf ("%d", &valNum);

  vector<int> arr (valNum);
  for (auto &i : arr)
    scanf ("%d", &i);

  auto ite = partition (arr.begin (), arr.end (), valNum / 2 - 1);
  int sumA = accumulate (arr.begin (), ite + 1, 0);
  int sumB = accumulate (ite + 1, arr.end (), 0);

  if (valNum % 2)
    printf ("1 ");
  else
    printf ("0 ");
  printf ("%d\n", sumB - sumA);

  return 0;
}