#include <cstdio>

int main ()
{
  printf ("#");
  for (int i = 0; i < 3; ++i)
  {
    int dec;
    scanf ("%d", &dec);

    char *map = "0123456789ABC";
    printf ("%c%c", map[dec / 13], map[dec % 13]);
  }
  printf ("\n");

  return 0;
}