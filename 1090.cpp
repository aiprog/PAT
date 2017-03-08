#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct Node
{
  int parent;
  int depth = -1;
};

void computeDepth (vector<Node> &tree, int nd)
{
  if (tree[nd].depth == -1)
  {
    computeDepth (tree, tree[nd].parent);
    tree[nd].depth = tree[tree[nd].parent].depth + 1;
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  double price, rate;
  scanf ("%lf %lf", &price, &rate);

  vector<Node> tree (nodeNum);
  for (int i = 0; i < nodeNum; ++i)
  {
    scanf ("%d", &tree[i].parent);
    if (tree[i].parent == -1)
      tree[i].depth = 1;
  }

  int max = -1, cnt = 0;
  for (int i = 0; i < nodeNum; ++i)
  {
    computeDepth (tree, i);
    if (tree[i].depth > max)
    {
      max = tree[i].depth;
      cnt = 1;
    }
    else if (tree[i].depth == max)
      ++cnt;
  }
  printf ("%.2lf %d\n", pow (1 + rate / 100, max - 1) * price, cnt);

  return 0;
}