#include <cstdio>

struct Info
{
  int val;
  int beg;
  int end;
  int sum;
};

int main ()
{
  int num;
  scanf ("%d", &num);

  Info *tab = new Info[num];
  for (int i = 0; i < num; ++i)
    scanf ("%d", &tab[i].val);

  tab[0].sum = tab[0].val;
  tab[0].beg = tab[0].end = 0;

  for (int i = 1; i < num; ++i)
  {
    if (tab[i].val >= 0)
    {
      int max = tab[i].val, tmp = max, pos = i;
      for (int j = i - 1; j >= 0; --j)
      {
        tmp += tab[j].val;
        if (tmp > max)
        {
          max = tmp;
          pos = j;
        }
      }

      if (max > tab[i - 1].sum)
      {
        tab[i].beg = pos;
        tab[i].end = i;
        tab[i].sum = max;

        continue;
      }
    }

    tab[i].beg = tab[i - 1].beg;
    tab[i].end = tab[i - 1].end;
    tab[i].sum = tab[i - 1].sum;
  }

  if (tab[num - 1].sum < 0)
    printf ("0 %d %d\n", tab[0].val, tab[num - 1].val);
  else
    printf ("%d %d %d\n", tab[num - 1].sum, tab[tab[num - 1].beg].val, tab[tab[num - 1].end].val);

  delete[] tab;

  return 0;
}
