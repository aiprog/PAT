#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
  int cnt = 0;
  int parent = -1;
  int rank = 1;
};

int findSet (vector<Node> &tree, int nd)
{
  if (tree[nd].parent == -1)
    return nd;
  else
    return (tree[nd].parent = findSet (tree, tree[nd].parent));
}

void unionSet (vector<Node> &tree, int ndA, int ndB)
{
  int setA = findSet (tree, ndA), setB = findSet (tree, ndB);
  if (setA != setB)
  {
    if (tree[setA].rank < tree[setB].rank)
      swap (setA, setB);

    tree[setA].cnt += tree[setB].cnt;
    tree[setB].parent = setA;
    tree[setA].rank = max (tree[setA].rank, tree[setB].rank + 1);
  }
}

int main ()
{
  int picNum;
  scanf ("%d", &picNum);

  vector<Node> tree (10001);
  for (int i = 0; i < picNum; ++i)
  {
    int birdNum;
    scanf ("%d", &birdNum);

    int first = 0;
    for (int j = 0; j < birdNum; ++j)
    {
      int bird;
      scanf ("%d", &bird);

      if (!tree[bird].cnt)
        tree[bird].cnt = 1;

      if (!first)
        first = bird;

      unionSet (tree, first, bird);
    }
  }

  int treeNum = 0, birdNum = 0;
  for (auto &i : tree)
  {
    if (i.cnt && i.parent == -1)
    {
      ++treeNum;
      birdNum += i.cnt;
    }
  }
  printf ("%d %d\n", treeNum, birdNum);

  int reqNum;
  scanf ("%d", &reqNum);

  for (int i = 0; i < reqNum; ++i)
  {
    int birdA, birdB;
    scanf ("%d %d", &birdA, &birdB);

    if (findSet (tree, birdA) == findSet (tree, birdB))
      printf ("Yes\n");
    else
      printf ("No\n");
  }

  return 0;
}#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
  int cnt = 0;
  int parent = -1;
  int rank = 1;
};

int findSet (vector<Node> &tree, int nd)
{
  if (tree[nd].parent == -1)
    return nd;
  else
    return (tree[nd].parent = findSet (tree, tree[nd].parent));
}

void unionSet (vector<Node> &tree, int ndA, int ndB)
{
  int setA = findSet (tree, ndA), setB = findSet (tree, ndB);
  if (setA != setB)
  {
    if (tree[setA].rank < tree[setB].rank)
      swap (setA, setB);

    tree[setA].cnt += tree[setB].cnt;
    tree[setB].parent = setA;
    tree[setA].rank = max (tree[setA].rank, tree[setB].rank + 1);
  }
}

int main ()
{
  int picNum;
  scanf ("%d", &picNum);

  vector<Node> tree (10001);
  for (int i = 0; i < picNum; ++i)
  {
    int birdNum;
    scanf ("%d", &birdNum);

    int first = 0;
    for (int j = 0; j < birdNum; ++j)
    {
      int bird;
      scanf ("%d", &bird);

      if (!tree[bird].cnt)
        tree[bird].cnt = 1;

      if (!first)
        first = bird;

      unionSet (tree, first, bird);
    }
  }

  int treeNum = 0, birdNum = 0;
  for (auto &i : tree)
  {
    if (i.cnt && i.parent == -1)
    {
      ++treeNum;
      birdNum += i.cnt;
    }
  }
  printf ("%d %d\n", treeNum, birdNum);

  int reqNum;
  scanf ("%d", &reqNum);

  for (int i = 0; i < reqNum; ++i)
  {
    int birdA, birdB;
    scanf ("%d %d", &birdA, &birdB);

    if (findSet (tree, birdA) == findSet (tree, birdB))
      printf ("Yes\n");
    else
      printf ("No\n");
  }

  return 0;
}