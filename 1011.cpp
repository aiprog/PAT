#include <cstdio>

int main ()
{
  float odds[3][3];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      scanf ("%f", &odds[i][j]);

  int choice[3];
  float product = 1;

  for (int i = 0; i < 3; ++i)
  {
    choice[i] = 0;
    for (int j = 1; j < 3; ++j)
      if (odds[i][j] > odds[i][choice[i]])
        choice[i] = j;

    product *= odds[i][choice[i]];
  }

  for (int i = 0; i < 3; ++i)
  {
    if (choice[i] == 0)
      printf ("W ");
    else if (choice[i] == 1)
      printf ("T ");
    else
      printf ("L ");
  }
  printf ("%.2f\n", (product * 0.65 - 1) * 2);

  return 0;
}