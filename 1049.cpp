#include <cstdio>
#include <cstring>

int main ()
{
  int val[11] = { 1 }, one[11] = { 0 };
  for (int i = 1; i < 11; ++i)
  {
    val[i] = 10 * val[i - 1];
    one[i] = 10 * one[i - 1] + val[i - 1];
  }

  char num[12];
  scanf ("%s", num);

  int len = (int)strlen (num), cnt = 0;
  for (int i = 0; i < len; ++i)
  {
    int digit = num[i] - '0';
    int remainLen = len - i - 1;

    cnt += digit * one[remainLen];
    if (digit == 1)
    {
      int remainNum = 0;
      sscanf (num + i + 1, "%d", &remainNum);
      cnt += remainNum + 1;
    }
    else if (digit > 1)
      cnt += val[remainLen];
  }
  printf ("%d\n", cnt);

  return 0;
}