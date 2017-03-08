#include <cstdio>
#include <set>

using namespace std;

int main ()
{
  int valNum;
  scanf ("%d", &valNum);

  set<int> cnt;
  for (int i = 0; i < valNum; ++i)
  {
    char buf[10];
    scanf ("%s", buf);

    int sum = 0;
    for (int j = 0; buf[j]; ++j)
      sum += buf[j] - '0';

    cnt.insert (sum);
  }

  printf ("%llu\n", cnt.size ());
  for (auto ite = cnt.begin (); ite != cnt.end (); ++ite)
  {
    if (ite != cnt.begin ())
      printf (" ");
    printf ("%d", *ite);
  }
  printf ("\n");

  return 0;
}