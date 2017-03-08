#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Player
{
  int weight;
  int order;
};

int main ()
{
  int playerNum, numInGroup;
  scanf ("%d %d", &playerNum, &numInGroup);

  vector<Player> player (playerNum);
  vector<int> order2Index (playerNum);
  
  for (int i = 0; i < playerNum; ++i)
    scanf ("%d", &player[i].weight);

  for (int i = 0; i < playerNum; ++i)
  {
    int order;
    scanf ("%d", &order);

    player[order].order = i;
    order2Index[i] = order;
  }

  auto playerCmp = [](const Player &p1, const Player &p2) { return p1.order < p2.order; };
  sort (player.begin (), player.end (), playerCmp);

  list<Player> lis (player.begin (), player.end ());
  vector<int> rank (playerNum);

  while (lis.size () != 1)
  {
    int curRank = (int)lis.size () / numInGroup;
    if (lis.size () % numInGroup)
      ++curRank;
    ++curRank;

    auto beg = lis.begin (), end = lis.begin ();
    while (end != lis.end ())
    {
      int maxWeight = -1;
      int cnt = 0;

      while (cnt < numInGroup && end != lis.end ())
      {
        if (maxWeight == -1 || end->weight > maxWeight)
          maxWeight = end->weight;

        ++cnt;
        ++end;
      }

      while (beg != end)
      {
        if (beg->weight != maxWeight)
        {
          rank[order2Index[beg->order]] = curRank;
          beg = lis.erase (beg);
        }
        else
          ++beg;
      }
    }
  }
  rank[order2Index[lis.front ().order]] = 1;

  for (int i = 0; i < playerNum; ++i)
  {
    printf ("%d", rank[i]);
    if (i != playerNum - 1)
      printf (" ");
    else
      printf ("\n");
  }

  return 0;
}