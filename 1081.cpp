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
    LONG r =  a % b;
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

int main ()
{
  int num;
  scanf ("%d", &num);

  LONG numerator = 0, denominator = 1;
  for (int i = 0; i < num; ++i)
  {
    LONG a, b;
    scanf ("%lld/%lld", &a, &b);

    if (a)
    {
      if (numerator)
      {
        simplify (numerator, denominator);
        simplify (a, b);

        LONG lcm = LCM (denominator, b);
        numerator *= lcm / denominator;
        a *= lcm / b;

        numerator += a;
        denominator = lcm;
      }
      else
      {
        numerator = a;
        denominator = b;
      }
    }
  }

  LONG integer = numerator / denominator;
  numerator %= denominator;

  if (!integer && !numerator)
    printf ("0");
  
  if (integer)
    printf ("%lld", integer);

  if (numerator)
  {
    simplify (numerator, denominator);
    if (integer)
      printf (" ");
    printf ("%lld/%lld", numerator, denominator);
  }
  printf ("\n");

  return 0;
}