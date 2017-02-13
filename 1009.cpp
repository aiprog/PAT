#include <cstdio>
#include <vector>
#include <algorithm>

struct Poly
{
  int exp;
  float coef;
};

int main ()
{
  int n1;
  scanf ("%d", &n1);

  Poly *p1 = new Poly[n1];
  for (int i = 0; i < n1; ++i)
    scanf ("%d %f", &p1[i].exp, &p1[i].coef);

  int n2;
  scanf ("%d", &n2);

  Poly *p2 = new Poly[n2];
  for (int i = 0; i < n2; ++i)
  scanf ("%d %f", &p2[i].exp, &p2[i].coef);

  std::vector<Poly> tmp;
  for (int i = 0; i < n1; ++i)
    for (int j = 0; j < n2; ++j)
      tmp.push_back (Poly {p1[i].exp + p2[j].exp, p1[i].coef * p2[j].coef});

  auto cmp = [](const Poly &p1, const Poly &p2) { return p1.exp >= p2.exp; };
  std::sort (tmp.begin (), tmp.end (), cmp);

  std::vector<Poly> prod;
  int exp = -1;
  float coef = 0;

  for (auto i : tmp)
  {
    if (i.exp == exp)
      coef += i.coef;
    else
    {
      if (coef)
        prod.push_back (Poly {exp, coef});

      exp = i.exp;
      coef = i.coef;
    }
  }
  prod.push_back (Poly {exp, coef});

  printf ("%lu", prod.size ());
  for (auto i : prod)
    printf (" %d %.1f", i.exp, i.coef);
  printf ("\n");

  delete[] p1;
  delete[] p2;

  return 0;
}
