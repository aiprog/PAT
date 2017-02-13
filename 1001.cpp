#include <cstdio>
#include <cstring>

int main ()
{
  int a, b;
  scanf ("%d %d", &a, &b);

  int sum = a + b;
  if (sum < 0)
  {
    sum = -sum;
    printf ("-");
  }

  char buf[12] = { 0 };
  sprintf (buf, "%d", sum);

  int len = strlen (buf), commas = (strlen (buf) - 1) / 3;
  for (int i = len - 1; i >= 0; --i)
  {
    if (i != len - 1 && (len - i) % 3 == 1)
    {
      --commas;
      buf[i + commas + 1] = ',';
    }

    buf[i + commas] = buf[i];
  }

  printf ("%s\n", buf);

  return 0;
}
