#include <cstdio>
#include <cstring>

int main ()
{
  char str[90];
  scanf ("%s", str);

  int len = (int)strlen (str), lenVer = (len + 2) / 3 - 1, lenSpa = len - 2 * lenVer - 2;
  for (int i = 0; i < lenVer; ++i)
  {
    printf ("%c", str[i]);
    for (int j = 0; j < lenSpa; ++j)
      printf (" ");
    printf ("%c\n", str[len - 1- i]);
  }

  str[len - lenVer] = 0;
  printf ("%s\n", str + lenVer);

  return 0;
}