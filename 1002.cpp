#include <cstdio>
#include <cstring>

typedef struct _poly
{
  int exp;
  float coef;
} Poly;

int main ()
{
  int k1, k2, k3;
  Poly *p1, *p2, *p3;

  scanf ("%d", &k1);
  p1 = new Poly[k1];
  for (int i = 0; i < k1; ++i)
    scanf ("%d %f", &p1[i].exp, &p1[i].coef);

  scanf ("%d", &k2);
  p2 = new Poly[k2];
  for (int i = 0; i < k2; ++i)
    scanf ("%d %f", &p2[i].exp, &p2[i].coef);

  k3 = k1 + k2;
  p3 = new Poly[k3];

  int i = 0, j = 0, k = 0;
  while (i < k1 && j <k2)
  {
    p3[k].exp = p1[i].exp;
    if (p2[j].exp > p3[k].exp)
      p3[k].exp = p2[j].exp;

    p3[k].coef = 0;
    while (1)
    {
      if (p1[i].exp == p3[k].exp)
      {
        p3[k].coef += p1[i].coef;
        ++i;

        continue;
      }

      if (p2[j].exp == p3[k].exp)
      {
        p3[k].coef += p2[j].coef;
        ++j;
      }
      else
      {
        if (p3[k].coef)
          ++k;

        break;
      }
    }
  }

  if (i < k1)
  {
    memcpy (p3 + k, p1 + i, (k1 - i) * sizeof (Poly));
    k += k1 - i;
  }

  if (j < k2)
  {
    memcpy (p3 + k, p2 + j, (k2 - j) * sizeof (Poly));
    k += k2 - j;
  }

  printf ("%d", k);
  for (int i = 0; i < k; ++i)
    printf (" %d %.1f", p3[i].exp, p3[i].coef);
  printf ("\n");

  delete[] p1;
  delete[] p2;
  delete[] p3;

  return 0;
}
