#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
  bool root = true;
  int child[2];
};

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  vector<Node> tree (nodeNum);
  for (int i = 0; i < nodeNum; ++i)
  {
    char lstr[5], rstr[5];
    scanf ("%s %s", lstr, rstr);

    int left = -1, right = -1;
    sscanf (lstr, "%d", &left);
    sscanf (rstr, "%d", &right);

    if (left != -1)
      tree[left].root = false;

    if (right != -1)
      tree[right].root = false;

    tree[i].child[0] = left;
    tree[i].child[1] = right;
  }

  int root = (int)(find_if (tree.begin (), tree.end (), [](Node &nd) { return nd.root; }) - tree.begin ());
  queue<int> que;
  que.push (root);

  int front;
  bool noChild = false, CBT = true;

  while (!que.empty ())
  {
    front = que.front ();
    que.pop ();

    for (int i = 0; i < 2; ++i)
    {
      int &child = tree[front].child[i];
      if (noChild)
      {
        if (child != -1)
        {
          CBT = false;
          break;
        }
      }
      else
      {
        if (child != -1)
          que.push (child);
        else
          noChild = true;
      }
    }
  }

  if (CBT)
    printf ("YES %d\n", front);
  else
    printf ("NO %d\n", root);

  return 0;
}