#include <cstdio>

bool isPrime (int num)
{
  if (num == 1)
    return false;

  bool prime = true;
  for (int i = 2; i * i <= num; ++i)
  {
    if (num % i == 0)
    {
      prime = false;
      break;
    }
  }

  return prime;
}

int main ()
{
  while (1)
  {
    int num, radix;
    scanf ("%d %d", &num, &radix);
    if (num < 0)
      break;

    if (isPrime (num))
    {
      int buf[20];
      int pos = 0;

      while (num)
      {
        buf[pos] = num % radix;
        num /= radix;

        ++pos;
      }

      int value = 0;
      for (int i = 0; i < pos; ++i)
        value = value * radix + buf[i];

      if (isPrime (value))
        printf ("Yes\n");
      else
        printf ("No\n");
    }
    else
      printf ("No\n");
  }

  return 0;
}