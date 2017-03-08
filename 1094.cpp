#include <cstdio>
#include <vector>

using namespace std;

struct Node
{
  int parent;
  int depth = -1;
};

void computeDepth (vector<Node> &tree, vector<int> &depth, int nd)
{
  if (tree[nd].depth == -1)
  {
    computeDepth (tree, depth, tree[nd].parent);
    tree[nd].depth = tree[tree[nd].parent].depth + 1;
    ++depth[tree[nd].depth];
  }
}

int main ()
{
  int nodeNum, parentNum;
  scanf ("%d %d", &nodeNum, &parentNum);

  vector<Node> tree (nodeNum + 1);
  tree[1].depth = 1;

  for (int i = 0; i < parentNum; ++i)
  {
    int parent, childNum;
    scanf ("%d %d", &parent, &childNum);

    for (int j = 0; j < childNum; ++j)
    {
      int child;
      scanf ("%d", &child);
      tree[child].parent = parent;
    }
  }

  vector<int> depth (nodeNum + 1);
  depth[1] = 1;

  for (int i = 1; i <= nodeNum; ++i)
    computeDepth (tree, depth, i);

  int gen = 1, cnt = 1;
  for (int i = 2; i <= nodeNum; ++i)
  {
    if (depth[i] > cnt)
    {
      gen = i;
      cnt = depth[i];
    }
  }
  printf ("%d %d\n", cnt, gen);

  return 0;
}

