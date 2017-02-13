#include <cstdio>
#include <queue>
#include <algorithm>

struct Win
{
  int nextTime = 0;
  std::queue<int> customer;
};

struct Customer
{
  int transactionTime;
  int finishTime = -1;
};

int main ()
{
  int winNum, capacity, customerNum, queryNum;
  scanf ("%d %d %d %d", &winNum, &capacity, &customerNum, &queryNum);

  Win *win = new Win[winNum];
  Customer *customer = new Customer[customerNum];

  for (int i = 0; i < customerNum; ++i)
    scanf ("%d", &customer[i].transactionTime);

  for (int i = 0; i < customerNum;)
  {
    auto winCmp = [](const Win &w1, const Win &w2) { return w1.customer.size () < w2.customer.size (); };
    Win *bestWin = std::min_element (win, win + winNum, winCmp);

    if (bestWin->customer.size () != capacity)
    {
      bestWin->customer.push (i);
      if (bestWin->customer.size () == 1)
        bestWin->nextTime += customer[i].transactionTime;

      ++i;
    }
    else
    {
      auto winCmp = [](const Win &w1, const Win &w2) { return w1.nextTime < w2.nextTime; };
      Win *minWin = std::min_element (win, win + winNum, winCmp);
      int nextCustomer = minWin->customer.front ();

      customer[nextCustomer].finishTime = minWin->nextTime;
      minWin->customer.pop ();

      if (minWin->customer.size ())
        minWin->nextTime += customer[minWin->customer.front ()].transactionTime;
    }
  }

  for (int i = 0; i < winNum; ++i)
  {
    while (!win[i].customer.empty ())
    {
      int nextCustomer = win[i].customer.front ();
      customer[nextCustomer].finishTime = win[i].nextTime;

      win[i].customer.pop ();
      if (!win[i].customer.empty ())
        win[i].nextTime += customer[win[i].customer.front ()].transactionTime;
    }
  }

  for (int i = 0; i < queryNum; ++i)
  {
    int query;
    scanf ("%d", &query);
    --query;

    int finishTime = customer[query].finishTime;
    if (finishTime - customer[query].transactionTime <= 9 * 60 - 1)
      printf ("%02d:%02d\n", 8 + finishTime / 60, finishTime % 60);
    else
      printf ("Sorry\n");
  }

  delete[] win;
  delete[] customer;

  return 0;
}