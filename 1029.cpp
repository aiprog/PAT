#include <cstdio>
#include <vector>
#include <iterator>

using LONG = long long;
using PTR = std::vector<LONG>::iterator;

LONG findMedian (PTR beg1, PTR end1, PTR beg2, PTR end2)
{
  PTR mid1 = beg1 + (end1 - beg1 - 1) / 2, mid2 = beg2 + (end2 - beg2 - 1) / 2;
  if (beg1 == end1)
    return *mid2;
  else if (beg2 == end2)
    return *mid1;

  if (*mid1 == *mid2)
    return *mid1;
  else if (*mid1 < *mid2)
  {
    std::swap (beg1, beg2);
    std::swap (end1, end2);
    std::swap (mid1, mid2);
  }

  int len = (int)(end1 - mid1 - 1);
  if (mid2 - beg2 < len)
    len = (int)(mid2 - beg2);

  if (len)
    return findMedian (beg1, end1 - len, beg2 + len, end2);
  else
  {
    int sz = (int)(end1 - beg1) + (int)(end2 - beg2);
    LONG mid;

    for (int i = 0; i < (sz + 1) / 2; ++i)
    {
      if (beg1 == end1)
      {
        mid = *beg2;
        ++beg2;
      }
      else if (beg2 == end2)
      {
        mid = *beg1;
        ++beg1;
      }
      else if (*beg1 < *beg2)
      {
        mid = *beg1;
        ++beg1;
      }
      else
      {
        mid = *beg2;
        ++beg2;
      }
    }

    return mid;
  }
}

int main ()
{
  int sz1;
  scanf ("%d", &sz1);

  std::vector<LONG> seq1 (sz1);
  for (int i = 0; i < sz1; ++i)
  {
    LONG tmp;
    scanf ("%lld", &tmp);
    seq1[i] = tmp;
  }

  int sz2;
  scanf ("%d", &sz2);

  std::vector<LONG> seq2 (sz2);
  for (int i = 0; i < sz2; ++i)
  {
    LONG tmp;
    scanf ("%lld", &tmp);
    seq2[i] = tmp;
  }

  printf ("%lld\n", findMedian (seq1.begin (), seq1.end (), seq2.begin (), seq2.end ()));

  return 0;
}