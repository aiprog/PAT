#include <cstdio>

int main ()
{
  int caseNum;
  scanf ("%d", &caseNum);

  for (int i = 0; i < caseNum; ++i)
  {
    long long a, b, c;
    scanf ("%lld %lld %lld", &a, &b, &c);

    printf ("Case #%d: ", i + 1);
    long long sum = a + b;

    if (a > 0 && b > 0 && sum < 0)
      printf ("true\n");
    else if (a < 0 && b < 0 && sum >= 0)
      printf ("false\n");
    else if (sum > c)
      printf ("true\n");
    else
      printf ("false\n");
  }

  return 0;
}