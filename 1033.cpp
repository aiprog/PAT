#include <cstdio>
#include <vector>
#include <algorithm>

struct Stat
{
  double dist;
  double price;
};

int main ()
{
  double capacity, dstDist, distPerUnit, distPerTank;
  int statNum;

  scanf ("%lf %lf %lf %d", &capacity, &dstDist, &distPerUnit, &statNum);
  distPerTank = capacity * distPerUnit;

  std::vector<Stat> stat (statNum);
  for (int i = 0; i < statNum; ++i)
    scanf ("%lf %lf", &stat[i].price, &stat[i].dist);
    
  auto statCmp = [](const Stat &s1, const Stat &s2) { return s1.dist < s2.dist; };
  std::sort (stat.begin (), stat.end (), statCmp);

  if (stat[0].dist)
  {
    printf ("The maximum travel distance = 0.00\n");
    return 0;
  }

  double curGas = 0, cost = 0;
  int curStat = 0;

  while (1)
  {
    int cheapStat = -1, expenStat = -1;
    for (int i = curStat + 1; i < statNum && stat[i].dist - stat[curStat].dist <= distPerTank; ++i)
    {
      if (stat[i].price < stat[curStat].price)
      {
        cheapStat = i;
        break;
      }
      else if (expenStat == -1 || stat[i].price <= stat[expenStat].price)
        expenStat = i;
    }

    if (cheapStat != -1)
    { 
      cost += ((stat[cheapStat].dist - stat[curStat].dist) / distPerUnit - curGas) * stat[curStat].price;
      curGas = 0;
      curStat = cheapStat;
    }
    else
    { 
      if (stat[curStat].dist + distPerTank >= dstDist)
      {
        cost += ((dstDist - stat[curStat].dist) / distPerUnit - curGas) * stat[curStat].price;
        printf ("%.2lf\n", cost);
        break;
      }

      if (expenStat != -1)
      {
        cost += (capacity - curGas) * stat[curStat].price;
        curGas = capacity - (stat[expenStat].dist - stat[curStat].dist) / distPerUnit;
        curStat = expenStat;
      }
      else
      {
        printf ("The maximum travel distance = %.2lf\n", stat[curStat].dist + distPerTank);
        break;
      }
    }
  }

  return 0;
}