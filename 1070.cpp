#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Cake
{
  double amout;
  double price;
  double average;
};

int main ()
{
  int type;
  double demand;
  scanf ("%d %lf", &type, &demand);

  vector<Cake> inventory (type);
  for (int i = 0; i < type; ++i)
    scanf ("%lf", &inventory[i].amout);
  for (int i = 0; i < type; ++i)
    scanf ("%lf", &inventory[i].price);
  for (int i = 0; i < type; ++i)
    inventory[i].average = inventory[i].price / inventory[i].amout;

  auto cakeCmp = [](const Cake &cakeA, const Cake &cakeB) { return cakeA.average > cakeB.average; };
  sort (inventory.begin (), inventory.end (), cakeCmp);

  double profit = 0;
  for (int i = 0; i < type && demand; ++i)
  {
    double cnt = min (1.0 * demand, inventory[i].amout);
    demand -= cnt;
    profit += cnt * inventory[i].average;
  }
  printf ("%.2lf\n", profit);

  return 0;
}