#include <cstdio>
#include <vector>

int main ()
{
  int betNum;
  scanf ("%d", &betNum);

  int cnt[10000 + 1] = { 0 };
  std::vector<int> bet (betNum);

  for (int i = 0; i < betNum; ++i)
  {
    scanf ("%d", &bet[i]);
    ++cnt[bet[i]];
  }

  for (auto &i : bet)
  {
    if (cnt[i] == 1)
    {
      printf ("%d\n", i);
      return 0;
    }
  }
  printf ("None\n");

  return 0;
}