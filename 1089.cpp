#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int eleNum;
  scanf ("%d", &eleNum);

  vector<int> init (eleNum), part (eleNum), backup (eleNum);
  for (auto &i : init)
    scanf ("%d", &i);
  backup = init;

  for (auto &i : part)
    scanf ("%d", &i);

  int flag = false;
  for (int i = 1; i < eleNum; ++i)
  {
    int tmp = init[i];
    int j = i;

    while (j && init[j - 1] > tmp)
    {
      init[j] = init[j - 1];
      --j;
    }
    init[j] = tmp;

    if (flag)
      break;
    else if (init == part)
      flag = true;
  }

  if (flag)
    printf ("Insertion Sort\n");
  else
  {
    init = backup;
    vector<int> tmp (eleNum);
    for (int bs = 1;; bs *= 2)
    {
      int beg = 0, mid, end;
      while (beg < eleNum)
      {
        if (eleNum - beg > bs)
        {
          mid = beg + bs - 1;
          end = min (mid + bs, eleNum - 1);

          int iteA = beg, iteB = mid + 1, iteC = 0;
          while (iteA != mid + 1 && iteB != end + 1)
          {
            if (init[iteA] < init[iteB])
              tmp[iteC++] = init[iteA++];
            else
              tmp[iteC++] = init[iteB++];
          }

          if (iteA != mid + 1)
            copy (init.begin () + iteA, init.begin () + mid + 1, tmp.begin () + iteC);
          else
            copy (init.begin () + iteB, init.begin () + end + 1, tmp.begin () + iteC);
          copy (tmp.begin (), tmp.begin () + end - beg + 1, init.begin () + beg);

          beg = end + 1;
        }
        else
          beg = eleNum;
      }

      if (flag)
        break;
      else if (init == part)
        flag = true;
    }

    printf ("Merge Sort\n");
  }
  
  for (int i = 0; i < init.size (); ++i)
  {
    if (i)
      printf (" ");
    printf ("%d", init[i]);
  }
  printf ("\n");


  return 0;
}