#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
  int key;
  int left = -1;
  int right = -1;
};

void insertBST (vector<Node> &tree, int &next, int nd, int key)
{
  if (next == 0)
    tree[next++].key = key;
  else if (key <= tree[nd].key)
  {
    if (tree[nd].left == -1)
    {
      tree[nd].left = next;
      tree[next++].key = key;
    }
    else
      insertBST (tree, next, tree[nd].left, key);
  }
  else
  {
    if (tree[nd].right == -1)
    {
      tree[nd].right = next;
      tree[next++].key = key;
    }
    else
      insertBST (tree, next, tree[nd].right, key);
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  vector<Node> tree (nodeNum);
  int next = 0;

  for (int i = 0; i < nodeNum; ++i)
  {
    int key;
    scanf ("%d", &key);
    insertBST (tree, next, 0, key);
  }

  vector<queue<int>> que (2);
  vector<int> cnt;
  
  int curQue = 1;
  que[0].push (0);

  while (!que[0].empty () || !que[1].empty ())
  {
    curQue = 1 - curQue;
    cnt.push_back ((int)que[curQue].size ());

    while (!que[curQue].empty ())
    {
      int front = que[curQue].front ();
      que[curQue].pop ();

      if (tree[front].left != -1)
        que[1 - curQue].push (tree[front].left);

      if (tree[front].right != -1)
        que[1 - curQue].push (tree[front].right);
    }
  }

  int sz = (int)cnt.size ();
  printf ("%d + %d = %d\n", cnt[sz - 1], cnt[sz - 2], cnt[sz - 1] + cnt[sz - 2]);

  return 0;
}