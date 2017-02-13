#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

struct Win
{
  int nextTime = 0;
  int customer = -1;
};

struct Customer
{
  int arriveTime;
  int finishTime;
  int serviceTime;
  int remainTime;
};

int main ()
{
  int customerNum, winNum;
  scanf ("%d %d", &customerNum, &winNum);

  std::vector<Customer> customer;
  for (int i = 0; i < customerNum; ++i)
  {
    int hour, minute, second, serviceTime;
    scanf ("%d:%d:%d %d", &hour, &minute, &second, &serviceTime);
    serviceTime *= 60;

    int arriveTime = 3600 * hour + 60 * minute + second;
    if (arriveTime <= 17 * 3600)
      customer.push_back ({ arriveTime, -1, serviceTime, serviceTime });
  }
  customerNum = (int)customer.size ();

  auto customerCmp = [](const Customer &c1, const Customer &c2) { return c1.arriveTime < c2.arriveTime; };
  std::sort (customer.begin (), customer.end (), customerCmp);

  std::vector<Win> win (winNum);
  std::queue<int> customerQueue;

  int customerPtr = 0;
  while (customerPtr < customerNum && customer[customerPtr].arriveTime < 8 * 3600)
    customerQueue.push (customerPtr++);

  int curTime = 8 * 3600;
  while (1)
  {
    for (auto &w : win)
    {
      if (w.customer != -1 && w.nextTime == curTime)
      {
        if (customer[w.customer].remainTime)
          customerQueue.push (w.customer);
        else
          customer[w.customer].finishTime = curTime;

        w.customer = -1;
      }
    }

    if (customerPtr != customerNum && customer[customerPtr].arriveTime == curTime)
      customerQueue.push (customerPtr++);

    for (auto &w : win)
    {
      if (w.customer == -1)
      {
        if (!customerQueue.empty ())
        {
          int front = customerQueue.front ();
          w.customer = front;
          customerQueue.pop ();

          if (customer[front].remainTime > 3600)
          {
            w.nextTime = curTime + 3600;
            customer[front].remainTime -= 3600;
          }
          else
          {
            w.nextTime = curTime + customer[front].remainTime;
            customer[front].remainTime = 0;
          }
        }
        else
          break;
      }
    }
 
    int minTime = INT_MAX;
    for (auto &w : win)
    {
      if (w.customer != -1 && w.nextTime < minTime)
        minTime = w.nextTime;
    }

    if (customerPtr != customerNum && customer[customerPtr].arriveTime < minTime)
      minTime = customer[customerPtr].arriveTime;

    if (minTime != INT_MAX)
      curTime = minTime;
    else
      break;
  }

  int waitTime = 0;
  for (auto &c : customer)
    waitTime += c.finishTime - c.arriveTime - c.serviceTime;

  printf ("%.1lf\n", 1.0 * waitTime / customerNum / 60);

  return 0;
}