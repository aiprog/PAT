#include <cstdio>
#include <cstring>

int main ()
{
  char buf[12] = { 0 };
  scanf ("%s", buf);

  int sum = 0;
  for (int i = 0; buf[i]; ++i)
    sum += buf[i] - '0';

  memset (buf, 0, 12 * sizeof (char));
  sprintf (buf, "%d", sum);

  const char *map[10] = { "zero", "one", "two", "three", "four",
                          "five", "six", "seven", "eight", "nine" };

  printf ("%s", map[buf[0] - '0']);
  for (int i = 1; buf[i]; ++i)
    printf (" %s", map[buf[i] - '0']);
  printf ("\n");

  return 0;
}
