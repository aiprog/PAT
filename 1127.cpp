#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct Node
{
  int key;
  int left = -1;
  int right = -1;
};

int buildBT (vector<Node> &inorder, int inBeg, int inEnd, vector<Node> &postorder, int postBeg, int postEnd)
{
  if (inBeg >= inEnd)
    return -1;
  else if (inBeg + 1 == inEnd)
    return inBeg;
  else
  {
    int pivot = postorder[postEnd - 1].key;
    int ite = inBeg;

    while (ite != inEnd && inorder[ite].key != pivot)
      ++ite;

    int leftRoot = buildBT (inorder, inBeg, ite, postorder, postBeg, postBeg + (ite - inBeg));
    int rightRoot = buildBT (inorder, ite + 1, inEnd, postorder, postEnd + (ite - inEnd), postEnd - 1);

    inorder[ite].left = leftRoot;
    inorder[ite].right = rightRoot;

    return ite;
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  vector<Node> inorder (nodeNum), postorder (nodeNum);
  for (auto &i : inorder)
    scanf ("%d", &i.key);
  for (auto &i : postorder)
    scanf ("%d", &i.key);

  vector<deque<int>> deq (2);
  deq[0].push_back (buildBT (inorder, 0, nodeNum, postorder, 0, nodeNum));

  bool first = true;
  for (int ite = 1, direction = 0; !deq[1 - ite].empty ();)
  {
    ite = 1 - ite;
    direction = 1 - direction;

    while (!deq[ite].empty ())
    {
      int top;
      if (!direction)
      {
        top = deq[ite].front ();
        deq[ite].pop_front ();
      }
      else
      {
        top = deq[ite].back ();
        deq[ite].pop_back ();
      }

      if (!first)
        printf (" ");
      else
        first = false;
      printf ("%d", inorder[top].key);

      int child[2] = { inorder[top].left, inorder[top].right };
      if (direction)
        swap (child[0], child[1]);

      for (auto &i : child)
      {
        if (i != -1)
        {
          if (!direction)
            deq[1 - ite].push_back (i);
          else
            deq[1 - ite].push_front (i);
        }
      }
    }
  }
  printf ("\n");

  return 0;
}