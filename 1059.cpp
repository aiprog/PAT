#include <cstdio>

bool isPrime (long long num)
{
  if (num == 2)
    return true;
  else
  {
    for (long long i = 2; i * i <= num; ++i)
    {
      if (num % i == 0)
        return false;
    }

    return true;
  }
}

int main ()
{
  long long num;
  scanf ("%lld", &num);
  printf ("%lld=", num);

  if (num == 1)
    printf ("1\n");
  else
  {
    long long factor = 1;
    while (num > 1)
    {
      do
      {
        ++factor;
      } while (!isPrime (factor) || num % factor);

      int cnt = 0;
      while (num % factor == 0)
      {
        num /= factor;
        ++cnt;
      }

      printf ("%lld", factor);
      if (cnt > 1)
        printf ("^%d", cnt);

      if (num > 1)
        printf ("*");
    }
    printf ("\n");
  }

  return 0;
}