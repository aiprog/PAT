#include <cstdio>
#include <cstring>
#include <algorithm>

int main ()
{
  int cnt[10] = { 0 };
  char digit[22] = { 0 };

  scanf ("%s", digit);
  for (int i = 0; digit[i]; ++i)
    ++cnt[digit[i] - '0'];

  int carry = 0;
  for (int i = (int)strlen (digit) - 1; i >= 0; --i)
  {
    int num = 2 * (digit[i] - '0') + carry;
    if (num >= 10)
    {
      --cnt[num - 10];
      digit[i] = num - 10 + '0';
      carry = 1;
    }
    else
    {
      --cnt[num];
      digit[i] = num + '0';
      carry = 0;
    }
  }

  if (carry)
    printf ("No\n1");
  else
  {
    if (std::find_if (std::begin (cnt), std::end (cnt), [](const int &i) { return i; })
      != std::end (cnt))
      printf ("No\n");
    else
      printf ("Yes\n");
  }
  printf ("%s\n", digit);

  return 0;
}