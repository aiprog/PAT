#include <cstdio>
#include <cstring>

#define SZ 100

void reverse (char *src)
{
  int len = (int)strlen (src);

  for (int i = 0; i < len / 2; ++i)
  {
    char tmp = src[len - 1 - i];
    src[len - 1 - i] = src[i];
    src[i] = tmp;
  }
  src[len] = 0;
}

void reverseAndAdd (char *src)
{
  char tmp[SZ];
  strcpy (tmp, src);
  reverse (tmp);

  int carry = 0;
  int len = (int)strlen (src);

  for (int i = 0; i < len; ++i)
  {
    int sum = src[i] + tmp[i] - 2 * '0' + carry;
    if (sum >= 10)
    {
      src[i] = sum - 10 + '0';
      carry = 1;
    }
    else
    {
      src[i] = sum + '0';
      carry = 0;
    }
  }

  if (carry)
    src[len++] = '1';
  src[len] = 0;

  reverse (src);
}

int main ()
{
  char num[SZ];
  int step, cnt = 0;

  scanf ("%s %d", &num, &step);
  while (cnt < step)
  {
    char tmp[SZ];
    strcpy (tmp, num);

    reverse (tmp);
    if (!strcmp (tmp, num))
      break;

    ++cnt;
    reverseAndAdd (num);
  }
  printf ("%s\n%d\n", num, cnt);

  return 0;
}
