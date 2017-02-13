#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

struct Table
{
  int nextTime = 8 * 3600;
  int pairCnt = 0;
  int pair = -1;
  bool VIP = false;
};

struct Pair
{
  int arriveTime;
  int playTime;
  bool VIP;
};

void printTime (int second)
{
  printf ("%02d:%02d:%02d", second / 3600, second % 3600 / 60, second % 60);
}

void servePair (Table &table, std::vector<Pair> &pair, std::queue<int> &queue, int currentTime)
{
  int front = queue.front ();
  queue.pop ();

  table.nextTime = currentTime + pair[front].playTime;
  table.pair = front;
  table.pairCnt++;

  printTime (pair[front].arriveTime);
  printf (" ");
  printTime (currentTime);
  printf (" ");
  printf ("%d\n", (currentTime - pair[front].arriveTime + 30) / 60);
}

int main ()
{
  int pairNum;
  scanf ("%d", &pairNum);

  std::vector<Pair> pair (pairNum);
  for (int i = 0; i < pairNum; ++i)
  {
    int h, m, s, playTime, VIP;
    scanf ("%d:%d:%d %d %d", &h, &m, &s, &playTime, &VIP);
    if (playTime * 60 > 2 * 3600)
      playTime = 2 * 3600;
    else
      playTime *= 60;

    pair[i] = { h * 3600 + m * 60 + s, playTime, (bool)VIP };
  }

  auto pairCmp = [](const Pair &p1, const Pair &p2) { return p1.arriveTime < p2.arriveTime; };
  std::sort (pair.begin (), pair.end (), pairCmp);

  int tableNum, VIPNum;
  scanf ("%d %d", &tableNum, &VIPNum);

  std::vector<Table> table (tableNum);
  for (int i = 0; i < VIPNum; ++i)
  {
    int num;
    scanf ("%d", &num);
    table[num - 1].VIP = true;
  }

  std::queue<int> ordinaryQueue, VIPQueue;
  int pairPtr = 0, currentTime = 8 * 3600;

  while (currentTime < 21 * 3600)
  {
    while (pairPtr != pairNum && pair[pairPtr].arriveTime == currentTime)
    {
      if (pair[pairPtr].VIP)
        VIPQueue.push (pairPtr);
      else
        ordinaryQueue.push (pairPtr);

      ++pairPtr;
    }

    for (auto &i : table)
    {
      if (i.pair != -1 && i.nextTime == currentTime)
        i.pair = -1;

      if (i.pair == -1 && i.VIP && !VIPQueue.empty ())
        servePair (i, pair, VIPQueue, currentTime);
    }

    for (auto &i : table)
    {
      if (i.pair == -1)
      {
        if (ordinaryQueue.empty () && VIPQueue.empty ())
          break;
        else if (VIPQueue.empty () || (!ordinaryQueue.empty () &&
          pair[ordinaryQueue.front ()].arriveTime < pair[VIPQueue.front ()].arriveTime))
          servePair (i, pair, ordinaryQueue, currentTime);
        else
          servePair (i, pair, VIPQueue, currentTime);
      }
    }

    int minTime = INT_MAX;
    auto tableCmp = [](const Table &t1, const Table &t2)
    { return t1.pair == -1 && t2.pair == -1 ? false : t2.pair == -1 || (t1.pair != -1 && t1.nextTime < t2.nextTime); };
    auto tmp = std::min_element (table.begin (), table.end (), tableCmp);

    if (tmp->pair != -1)
      minTime = tmp->nextTime;

    if (pairPtr != pairNum && pair[pairPtr].arriveTime < minTime)
      minTime = pair[pairPtr].arriveTime;

    currentTime = minTime;
  }
  
  for (auto ite = table.begin (); ite != table.end (); ++ite)
  {
    if (ite != table.begin ())
      printf (" ");
    printf ("%d", ite->pairCnt);
  }
  printf ("\n");

  return 0;
}