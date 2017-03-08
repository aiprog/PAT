#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

using LONG = long long;

LONG GCD (LONG a, LONG b)
{
  a = abs (a);
  b = abs (b);

  if (b > a)
    swap (a, b);

  while (a % b)
  {
    LONG r = a % b;
    a = b;
    b = r;
  }

  return b;
}

LONG LCM (LONG a, LONG b)
{
  a = abs (a);
  b = abs (b);

  return a / GCD (a, b) * b;
}

void simplify (LONG &a, LONG &b)
{
  LONG gcd = GCD (a, b);
  a /= gcd;
  b /= gcd;
}

void rationalPrint (LONG a, LONG b)
{
  if (!b)
    printf ("Inf");
  else
  {
    if (!a)
      printf ("0");
    else
    {
      simplify (a, b);
      LONG integer = a / b;
      a = a % b;

      if (integer < 0 || a < 0)
        printf ("(-");
      if (integer)
        printf ("%lld", abs (integer));
      if (a)
      {
        if (integer)
          printf (" ");
        printf ("%lld/%lld", abs (a), b);
      }
      if (integer < 0 || a < 0)
        printf (")");
    }
  }
}

void rationalAdd (LONG a, LONG b, LONG c, LONG d)
{
  if (!a)
    rationalPrint (c, d);
  else if (!c)
    rationalPrint (a, b);
  else
  {
    simplify (a, b);
    simplify (c, d);

    LONG e, f;
    f = LCM (b, d);
    e = a * (f / b) + c * (f / d);
    rationalPrint (e, f);
  }

}

void rationalSub (LONG a, LONG b, LONG c, LONG d)
{
  rationalAdd (a, b, -c, d);
}

void rationalMul (LONG a, LONG b, LONG c, LONG d)
{
  if (!d)
    printf ("Inf");
  else if (!a || !c)
    printf ("0");
  else
  {
    simplify (a, b);
    simplify (a, d);
    simplify (c, b);
    simplify (c, d);

    LONG e = a * c, f = b * d;
    if (f < 0)
    {
      e = -e;
      f = -f;
    }

    rationalPrint (e, f);
  }
}

void rationalDiv (LONG a, LONG b, LONG c, LONG d)
{
  rationalMul (a, b, d, c);
}

int main ()
{
  LONG a, b, c, d;
  scanf ("%lld/%lld %lld/%lld", &a, &b, &c, &d);

  void (*func[4])(LONG, LONG, LONG, LONG) = { rationalAdd, rationalSub, rationalMul, rationalDiv };
  char *op = "+-*/";

  for (int i = 0; i < 4; ++i)
  {
    rationalPrint (a, b);
    printf (" %c ", op[i]);
    rationalPrint (c, d);
    printf (" = ");
    func[i] (a, b, c, d);
    printf ("\n");
  }

  return 0;
}