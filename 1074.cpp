#include <cstdio>
#include <vector>
#include <list>

using namespace std;

struct Node
{
  int value;
  int next;
};

struct NewNode
{
  int addr;
  int value;
};

int main ()
{
  int head, nodeNum, group;
  scanf ("%d %d %d", &head, &nodeNum, &group);

  vector<Node> arr (100000);
  for (int i = 0; i < nodeNum; ++i)
  {
    int addr, value, next;
    scanf ("%d %d %d", &addr, &value, &next);
    arr[addr] = Node { value, next };
  }

  list<NewNode> st;
  int ite = head;
  bool first = true;

  while (1)
  {
    while (ite != -1 && st.size () != group)
    {
      st.push_back (NewNode { ite, arr[ite].value });
      ite = arr[ite].next;
    }

    bool reverse = true;
    if (st.size () != group)
      reverse = false;

    while (!st.empty ())
    {
      NewNode top;
      if (reverse)
      {
        top = st.back ();
        st.pop_back ();
      }
      else
      {
        top = st.front ();
        st.pop_front ();
      }

      if (!first)
        printf ("%05d\n", top.addr);
      else
        first = false;

      printf ("%05d %d ", top.addr, top.value);
    }

    if (ite == -1)
    {
      printf ("-1\n");
      break;
    }
  }

  return 0;
}