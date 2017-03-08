#include <cstdio>
#include <vector>

using namespace std;

struct Node
{
  bool leaf = false;
  double price = 0;
  int parent;
};

void computePrice (vector<Node> &tree, int nd, double rate)
{
  if (!tree[nd].price)
  {
    int parent = tree[nd].parent;
    computePrice (tree, parent, rate);
    tree[nd].price = (1 + rate / 100) * tree[parent].price;
  }
}

int main ()
{
  int num;
  double price, rate;
  scanf ("%d %lf %lf", &num, &price, &rate);

  vector<Node> tree (num);
  for (int i = 0; i < num; ++i)
  {
    int childNum;
    scanf ("%d", &childNum);

    if (!childNum)
      tree[i].leaf = true;

    for (int j = 0; j < childNum; ++j)
    {
      int child;
      scanf ("%d", &child);
      tree[child].parent = i;
    }
  }

  double min = 0;
  int cnt = 0;

  tree[0].price = price;
  for (int i = 0; i < num; ++i)
  {
    computePrice (tree, i, rate);
    if (tree[i].leaf)
    {
      if (!cnt || tree[i].price < min)
      {
        min = tree[i].price;
        cnt = 1;
      }
      else if (tree[i].price == min)
        ++cnt;
    }
  }
  printf ("%.4lf %d\n", min, cnt);

  return 0;
}