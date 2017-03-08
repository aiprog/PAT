#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
  int addr;
  int key;
  int next;
};

int main ()
{
  int nodeNum, head;
  scanf ("%d %d", &nodeNum, &head);

  vector<Node> memory (100000);
  for (int i = 0; i < nodeNum; ++i)
  {
    int addr, key, next;
    scanf ("%d %d %d", &addr, &key, &next);
    memory[addr] = { addr, key, next };
  }

  vector<Node> node;
  while (head != -1)
  {
    node.push_back (memory[head]);
    head = memory[head].next;
  }

  auto nodeCmp = [](const Node &n1, const Node &n2) { return n1.key < n2.key; };
  sort (node.begin (), node.end (), nodeCmp);

  printf ("%d ", (int)node.size ());
  if (node.size ())
    printf ("%05d\n", node[0].addr);
  else
    printf ("-1\n");

  for (int i = 0; i < node.size (); ++i)
  {
    printf ("%05d %d ", node[i].addr, node[i].key);
    if (i != node.size () - 1)
      printf ("%05d\n", node[i + 1].addr);
    else
      printf ("-1\n");
  }

  return 0;
}
