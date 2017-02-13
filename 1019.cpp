#include <cstdio>

int main ()
{
  int num, base;
  scanf ("%d %d", &num, &base);

  int buf[30];
  int len = 0;

  do
  {
    buf[len++] = num % base;
    num /= base;
  } while (num);

  bool flag = true;
  for (int i = 0; i < len / 2; ++i)
  {
    if (buf[i] != buf[len - 1 - i])
    {
      flag = false;
      break;
    }
  }

  if (flag)
    printf ("Yes\n");
  else
    printf ("No\n");

  printf ("%d", buf[len - 1]);
  for (int i = len - 2; i >= 0; --i)
    printf (" %d", buf[i]);
  printf ("\n");

  return 0;
}