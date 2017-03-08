#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Node
{
  int parent;
  double amount = 0;
  double price = 0;
};

void computePrice (vector<Node> &tree, double rate, int num)
{
  if (!tree[num].price)
  {
    int parent = tree[num].parent;
    computePrice (tree, rate, parent);
    tree[num].price = (1 + rate / 100) * tree[parent].price;
  }
}

int main ()
{
  int memberNum;
  double price, rate;
  scanf ("%d %lf %lf", &memberNum, &price, &rate);

  vector<Node> tree (memberNum);
  for (int i = 0; i < memberNum; ++i)
  {
    int childNum;
    scanf ("%d", &childNum);

    if (childNum)
    {
      for (int j = 0; j < childNum; ++j)
      {
        int child;
        scanf ("%d", &child);
        tree[child].parent = i;
      }
    }
    else
      scanf ("%lf", &tree[i].amount);
  }

  tree[0].parent = -1;
  tree[0].price = price;

  double sale = 0;
  for (int i = 0; i < memberNum; ++i)
  {
    if (tree[i].amount)
    {
      computePrice (tree, rate, i);
      sale += tree[i].amount * tree[i].price;
    }
  }
  printf ("%.1lf\n", sale);

  return 0;
}