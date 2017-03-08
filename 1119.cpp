#include <cstdio>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

struct Node
{
  int key;
  int left = -1;
  int right = -1;
};

using TREE = vector<Node>;

void buildBT (TREE &pre, int preBeg, int preEnd, TREE &post, int postBeg, int postEnd, int &num, int &root, bool build)
{
  if (preBeg == preEnd)
  {
    num = 1;
    root = -1;
  }
  else if (preBeg + 1 == preEnd)
  {
    if (pre[preBeg].key == post[postBeg].key)
    {
      num = 1;
      root = preBeg;
    }
    else
      num = 0;
  }
  else
  {
    set<int> preSet, postSet;
    int cnt = 0, i = 0;

    while (1)
    {
      if (preSet == postSet)
      {
        int numLeft, rootLeft;
        buildBT (pre, preBeg + 1, preBeg + 1 + i, post, postBeg, postBeg + i, numLeft, rootLeft, build);

        if (numLeft)
        {
          int numRigth, rootRight;
          buildBT (pre, preBeg + 1 + i, preEnd, post, postBeg + i, postEnd - 1, numRigth, rootRight, build);

          if (numRigth)
          {
            if (build)
            {
              pre[preBeg].left = rootLeft;
              pre[preBeg].right = rootRight;
              build = false;
            }

            cnt += numLeft * numRigth;
            if (cnt >= 2)
              break;
          }
        }
      }

      if (i < preEnd - preBeg - 1)
      {
        preSet.insert (pre[preBeg + 1 + i].key);
        postSet.insert (post[postBeg + i].key);
        ++i;
      }
      else
        break;
    }

    num = cnt;
    root = preBeg;
  }
}

void inorder (TREE &tree, int nd, ostringstream &strout)
{
  if (nd != -1)
  {
    inorder (tree, tree[nd].left, strout);
    strout << " " << tree[nd].key;
    inorder (tree, tree[nd].right, strout);
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  vector<Node> preorder (nodeNum), postorder (nodeNum);
  for (auto &i : preorder)
    scanf ("%d", &i.key);

  for (auto &i : postorder)
    scanf ("%d", &i.key);

  int num, root;
  buildBT (preorder, 0, nodeNum, postorder, 0, nodeNum, num, root, true);

  if (num > 1)
    printf ("No\n");
  else
    printf ("Yes\n");

  ostringstream strout;
  inorder (preorder, 0, strout);
  printf ("%s\n", strout.str ().c_str () + 1);

  return 0;
}