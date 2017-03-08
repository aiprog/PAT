#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
  int ID;
  int cnt = 0;
  int estate = 0;
  int area = 0;
  int rank = 1;
  int ancestor = -1;
  vector<int> parent;
  vector<int> child;
};

int findSet (vector<Node> &tree, int nd)
{
  if (tree[nd].ancestor == -1)
    return nd;
  else
    return (tree[nd].ancestor = findSet (tree, tree[nd].ancestor));
}

void unionSet (vector<Node> &tree, int ndA, int ndB)
{
  int setA = findSet (tree, ndA), setB = findSet (tree, ndB);
  if (setA != setB)
  {
    if (tree[setA].rank < tree[setB].rank)
      swap (setA, setB);

    tree[setB].ancestor = setA;
    if (tree[setB].ID < tree[setA].ID)
      tree[setA].ID = tree[setB].ID;
    tree[setA].cnt += tree[setB].cnt;
    tree[setA].estate += tree[setB].estate;
    tree[setA].area += tree[setB].area;
    tree[setA].rank = max (tree[setA].rank, tree[setB].rank + 1);
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  vector<Node> tree (10000);
  for (int i = 0; i < 10000; ++i)
  {
    tree[i].ID = i;
  }

  for (int i = 0; i < nodeNum; ++i)
  {
    int ID, mother, father;
    scanf ("%d %d %d", &ID, &mother, &father);
    tree[ID].cnt = 1;

    if (mother != -1)
    {
      tree[ID].parent.push_back (mother);
      if (!tree[mother].cnt)
        tree[mother].cnt = 1;
    }

    if (father != -1)
    {
      tree[ID].parent.push_back (father);
      if (!tree[father].cnt)
        tree[father].cnt = 1;
    }

    int childNum;
    scanf ("%d", &childNum);
    for (int j = 0; j < childNum; ++j)
    {
      int child;
      scanf ("%d", &child);
      tree[ID].child.push_back (child);

      if (!tree[child].cnt)
        tree[child].cnt = 1;
    }

    scanf ("%d %d", &tree[ID].estate, &tree[ID].area);
  }

  for (int i = 0; i < 10000; ++i)
  {
    if (tree[i].cnt)
    {
      for (auto &j : tree[i].parent)
        unionSet (tree, i, j);

      for (auto &j : tree[i].child)
        unionSet (tree, i, j);
    }
  }

  vector<Node> family;
  for (auto &i : tree)
  {
    if (i.cnt && i.ancestor == -1)
      family.push_back (i);
  }

  auto familyCmp = [](Node &ndA, Node &ndB)
  {
    double avgA = 1.0 * ndA.area / ndA.cnt, avgB = 1.0 * ndB.area / ndB.cnt;
    if (avgA != avgB)
      return avgA > avgB;
    else
      return ndA.ID < ndB.ID;
  };
  sort (family.begin (), family.end (), familyCmp);

  printf ("%llu\n", family.size ());
  for (auto &i : family)
    printf ("%04d %d %.3lf %.3lf\n", i.ID, i.cnt, 1.0 * i.estate / i.cnt, 1.0 * i.area / i.cnt);

  return 0;
}