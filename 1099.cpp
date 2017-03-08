#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
  int key;
  int left;
  int right;
};

void inorder (vector<Node> &tree, int nd, vector<int>::iterator &ite)
{
  if (nd != -1)
  {
    inorder (tree, tree[nd].left, ite);
    tree[nd].key = *ite++;
    inorder (tree, tree[nd].right, ite);
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  vector<Node> tree (nodeNum);
  for (auto &i : tree)
    scanf ("%d %d", &i.left, &i.right);

  vector<int> key (nodeNum);
  for (auto &i : key)
    scanf ("%d", &i);
  sort (key.begin (), key.end ());

  auto ite = key.begin ();
  inorder (tree, 0, ite);

  queue<int> que;
  bool first = true;

  que.push (0);
  while (!que.empty ())
  {
    int next = que.front ();
    que.pop ();

    if (!first)
      printf (" ");
    else
      first = false;
    printf ("%d", tree[next].key);

    if (tree[next].left != -1)
      que.push (tree[next].left);

    if (tree[next].right != -1)
      que.push (tree[next].right);
  }
  printf ("\n");

  return 0;
}