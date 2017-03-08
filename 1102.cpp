#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
  bool root = true;
  int left;
  int right;
};

void inorder (vector<Node> &tree, int nd, bool &first)
{
  if (nd != -1)
  {
    inorder (tree, tree[nd].right, first);
    if (!first)
      printf (" ");
    else
      first = false;
    printf ("%d", nd);
    inorder (tree, tree[nd].left, first);
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  vector<Node> tree (nodeNum);
  for (auto &i : tree)
  {
    char lStr[10], rStr[10];
    scanf ("%s %s", lStr, rStr);

    int left = -1, right = -1;
    if (lStr[0] != '-')
    {
      sscanf (lStr, "%d", &left);
      tree[left].root = false;
    }

    if (rStr[0] != '-')
    {
      sscanf (rStr, "%d", &right);
      tree[right].root = false;
    }

    i.left = left;
    i.right = right;
  }

  int root = (int)(find_if (tree.begin (), tree.end (), [](const Node &nd) { return nd.root; }) - tree.begin ());
  queue<int> que;
  que.push (root);

  bool first = true;
  while (!que.empty ())
  {
    int next = que.front ();
    que.pop ();

    if (!first)
      printf (" ");
    else
      first = false;
    printf ("%d", next);

    if (tree[next].right != -1)
      que.push (tree[next].right);

    if (tree[next].left != -1)
      que.push (tree[next].left);
  }
  printf ("\n");

  first = true;
  inorder (tree, root, first);
  printf ("\n");

  return 0;
}