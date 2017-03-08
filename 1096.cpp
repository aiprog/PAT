#include <cstdio>
#include <cmath>

using namespace std;

int main ()
{
  int num;
  scanf ("%d", &num);

  int beg = 2, end = 2, max = 1, maxBeg = num;
  while (1)
  {
    if (num % end == 0)
    {
      num /= end;
      ++end;
    }
    else
    {
      if (beg == end)
      {
        ++beg;
        ++end;
      }
      else
      {
        if (end - beg > max || (end - beg == max && beg < maxBeg))
        {
          max = end - beg;
          maxBeg = beg;
        }

        num *= beg;
        ++beg;
      }

      int prod = 1, i;
      for (i = end; i != max + beg + 1; ++i)
      {
        if (prod > 1.0 * num / i)
          break;
        prod *= i;
      }

      if (i != max + beg + 1)
        break;
    }
  }

  printf ("%d\n", max);
  for (int i = maxBeg; i != maxBeg + max; ++i)
  {
    if (i != maxBeg)
      printf ("*");
    printf ("%d", i);
  }
  printf ("\n");

  return 0;
}