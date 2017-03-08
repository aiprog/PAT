#include <cstdio>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
  int left = 0;
  int right = 0;
};

void postorder (vector<Node> &tree, int node, ostringstream &ostr)
{
  if (node)
  {
    postorder (tree, tree[node].left, ostr);
    postorder (tree, tree[node].right, ostr);
    ostr << " " << node;
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  vector<Node> tree (nodeNum + 1);
  stack<int> st;
  int head = 0, lastPop = 0, lastPush = 0;

  for (int i = 0; i < 2 * nodeNum; ++i)
  {
    char op[10];
    scanf ("%s", op);

    if (op[1] == 'u')
    {
      int node;
      scanf ("%d", &node);

      if (!head)
        head = node;

      if (lastPush)
        tree[lastPush].left = node;

      if (lastPop)
        tree[lastPop].right = node;

      lastPush = node;
      lastPop = 0;

      st.push (node);
    }
    else
    {
      lastPop = st.top ();
      lastPush = 0;

      st.pop ();
    }
  }

  ostringstream ostr;
  postorder (tree, head, ostr);
  printf ("%s\n", ostr.str ().c_str () + 1);

  return 0;
}