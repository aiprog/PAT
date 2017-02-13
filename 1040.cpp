#include <cstdio>
#include <iostream>
#include <cstring>

bool isSymmetric (char *str, int beg, int end)
{
  --end;
  while (beg <= end)
  {
    if (str[beg] != str[end])
      return false;

    ++beg;
    --end;
  }

  return true;
}

int main ()
{
  char str[1001];
  std::cin.getline (str, 1001);

  int len = (int)strlen (str), max[1001] = { 1 };
  for (int i = 1; i < len; ++i)
  {
    max[i] = max[i - 1];
    if (isSymmetric (str, i + 1 - (max[i] + 2), i + 1))
      max[i] += 2;
    else if (isSymmetric (str, i + 1 - (max[i] + 1), i + 1))
      max[i] += 1;
  }

  printf ("%d\n", max[len - 1]);

  return 0;
}