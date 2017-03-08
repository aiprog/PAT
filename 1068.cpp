#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int optionCmp (const list<int> &lisA, const list<int> &lisB)
{
  auto iteA = lisA.begin (), iteB = lisB.begin ();
  while (*iteA == *iteB)
  {
    ++iteA;
    ++iteB;
  }

  return *iteA < *iteB;
}

int main ()
{
  int coinNum, payment;
  scanf ("%d %d", &coinNum, &payment);

  vector<int> coin (coinNum);
  for (int i = 0; i < coinNum; ++i)
    scanf ("%d", &coin[i]);
  sort (coin.begin (), coin.end ());

  vector<list<int>> option (payment + 1);
  for (auto &i : coin)
  {
    for (int j = payment; j >= 0; --j)
    {
      if (i == j)
      {
        if (option[j].empty ())
          option[j].push_back (i);
      }
      else if (i < j)
      {
        if (!option[j - i].empty ())
        {
          if (option[j].empty ())
          {
            option[j] = option[j - i];
            option[j].push_back (i);
          }
          else
          {
            option[j - i].push_back (i);
            if (optionCmp (option[j - i], option[j]))
              option[j] = option[j - i];
            option[j - i].pop_back ();
          }
        }
      }
    }
  }

  if (!option[payment].empty ())
  {
    auto ite = option[payment].begin ();
    while (1)
    {
      printf ("%d", *ite);
      if (++ite != option[payment].end ())
        printf (" ");
      else
      {
        printf ("\n");
        break;
      }
    }
  }
  else
    printf ("No Solution\n");

  return 0;
}