#include <cstdio>

int main ()
{
  int num;
  scanf ("%d", &num);

  int cur = 0, time = 0;
  for (int i = 0; i < num; ++i)
  {
    int req;
    scanf ("%d", &req);

    if (req > cur)
      time += (req - cur) * 6 + 5;
    else
      time += (cur - req) * 4 + 5;

    cur = req;
  }

  printf ("%d\n", time);

  return 0;
}
