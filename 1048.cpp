#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int coinNum, payment;
  scanf ("%d %d", &coinNum, &payment);

  vector<int> coin (coinNum);
  for (int i = 0; i < coinNum; ++i)
    scanf ("%d", &coin[i]);
  sort (coin.begin (), coin.end ());

  for (int i = 0; i < coinNum; ++i)
  {
    if (2 * coin[i] > payment)
    {
      printf ("No Solution\n");
      return 0;
    }
    else
    {
      int remain = payment - coin[i];
      auto ite = lower_bound (coin.begin () + i + 1, coin.end (), remain);

      if (*ite == remain)
      {
        printf ("%d %d\n", coin[i], *ite);
        return 0;
      }
    }
  }
  printf ("No Solution\n");

  return 0;
}