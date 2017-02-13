#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

struct Option
{
  int min;
  vector<pair<int, int>> interval;
};

struct Diamond
{
  int value;
  int sum;
};

int main ()
{
  int chainLen, payment;
  scanf ("%d %d", &chainLen, &payment);

  vector<Diamond> chain (chainLen);
  for (int i = 0; i < chainLen; ++i)
  {
    scanf ("%d", &chain[i].value);
    chain[i].sum = chain[i].value;
    if (i)
      chain[i].sum += chain[i - 1].sum;
  }

  Option opt;
  int newMin = chain[0].value;

  for (int beg = 0, end = 0; beg < chain.size (); ++beg)
  {
    while (newMin < payment && end + 1 != chain.size ())
    {
      ++end;
      newMin += chain[end].value;
    }

    if (newMin < payment)
      break;
   
    if (!opt.interval.size () || newMin <= opt.min)
    {
      if (newMin < opt.min)
        opt.interval.clear ();

      opt.min = newMin;
      opt.interval.push_back ({ beg + 1, end + 1 });
    }

    newMin -= chain[beg].value;
  }

  for (auto &i : opt.interval)
    printf ("%d-%d\n", i.first, i.second);

  return 0;
}