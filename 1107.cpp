#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct Node
{
  int parent = -1;
  int cnt = 1;
  int hobby[1001] = { 0 };
};

int findSet (vector<Node> &tree, int nd)
{
  if (tree[nd].parent == -1)
    return nd;
  else
  {
    int parent = findSet (tree, tree[nd].parent);
    tree[nd].parent = parent;

    return parent;
  }
}

void unionSet (vector<Node> &tree, int ndA, int ndB)
{
  int setA = findSet (tree, ndA), setB = findSet (tree, ndB);
  if (setA != setB)
  {
    if (tree[setA].cnt < tree[setB].cnt)
      swap (setA, setB);

    tree[setB].parent = setA;
    tree[setA].cnt += tree[setB].cnt;

    for (int i = 1; i <= 1000; ++i)
    {
      if (tree[setB].hobby[i])
        tree[setA].hobby[i] = 1;
    }
  }
}

int main ()
{
  int num;
  scanf ("%d", &num);

  vector<Node> tree (num);
  for (int i = 0; i < num; ++i)
  {
    int hobbyNum;
    scanf ("%d:", &hobbyNum);

    for (int j = 0; j < hobbyNum; ++j)
    {
      int hobby;
      scanf ("%d", &hobby);
      tree[i].hobby[hobby] = 1;
    }
  }

  for (int i = 0; i < num; ++i)
  {
    for (int j = i + 1; j < num; ++j)
    {
      for (int k = 1; k <= 1000; ++k)
      {
        if (tree[i].hobby[k] && tree[j].hobby[k])
        {
          unionSet (tree, i, j);
          break;
        }
      }
    }
  }

  vector<int> res;
  for (int i = 0; i < num; ++i)
  {
    if (tree[i].parent == -1)
      res.push_back (tree[i].cnt);
  }
  sort (res.begin (), res.end (), greater<int> ());

  printf ("%llu\n", res.size ());
  for (int i = 0; i < (int)res.size (); ++i)
  {
    if (i)
      printf (" ");
    printf ("%d", res[i]);
  }
  printf ("\n");

  return 0;
}