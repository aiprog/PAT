#include <cstdio>

struct Node
{
  int cnt = 0;
  int next;
};

Node link[1000000];

int main ()
{
  int headA, headB, nodeNum;
  scanf ("%d %d %d", &headA, &headB, &nodeNum);

  for (int i = 0; i < nodeNum; ++i)
  {
    int src, dst;
    char ch;

    scanf ("%d %c %d", &src, &ch, &dst);
    link[src].next = dst;
  }

  int ite = headA;
  while (ite != -1)
  {
    ++link[ite].cnt;
    ite = link[ite].next;
  }

  ite = headB;
  while (ite != -1)
  {
    ++link[ite].cnt;
    ite = link[ite].next;
  }

  ite = headA;
  while (ite != -1 && link[ite].cnt != 2)
    ite = link[ite].next;

  if (ite != -1)
    printf ("%05d\n", ite);
  else
    printf ("-1\n");

  return 0;

}