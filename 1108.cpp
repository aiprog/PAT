#include <cstdio>
#include <cstring>

int main ()
{
  int valNum;
  scanf ("%d", &valNum);

  double sum = 0;
  int cnt = 0;

  for (int i = 0; i < valNum; ++i)
  {
    char buf[100] = { 0 }, tmp[100] = { 0 };
    scanf ("%s", buf);

    double val;
    sscanf (buf, "%lf", &val);
    sprintf (tmp, "%.2lf", val);

    int j;
    for (j = 0; j != (int)strlen (buf); ++j)
    {
      if (buf[j] != tmp[j])
        break;
    }

    if (val < -1000 || val > 1000 || j != (int)strlen (buf))
      printf ("ERROR: %s is not a legal number\n", buf);
    else
    {
      sum += val;
      ++cnt;
    }
  }

  if (cnt == 0)
    printf ("The average of 0 numbers is Undefined\n");
  else if (cnt == 1)
    printf ("The average of 1 number is %.2lf\n", sum / cnt);
  else
    printf ("The average of %d numbers is %.2lf\n", cnt, sum / cnt);

  return 0;
}