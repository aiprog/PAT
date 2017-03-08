#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void inorder (vector<int> &tree, int root, vector<int>::iterator &ite)
{
  if (root < tree.size ())
  {
    inorder (tree, 2 * root + 1, ite);
    tree[root] = *ite++;
    inorder (tree, 2 * root + 2, ite);
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  vector<int> key (nodeNum);
  for (int i = 0; i < nodeNum; ++i)
    scanf ("%d", &key[i]);
  sort (key.begin (), key.end ());

  vector<int> tree (nodeNum);
  auto ite = key.begin ();
  inorder (tree, 0, ite);

  queue<int> que;
  que.push (0);

  bool first = true;
  while (!que.empty ())
  {
    int parent = que.front ();
    que.pop ();

    if (first)
      first = false;
    else
      printf (" ");
    printf ("%d", tree[parent]);
  
    int leftChild = 2 * parent + 1, rightChild = leftChild + 1;
    if (leftChild < tree.size ())
      que.push (leftChild);
    if (rightChild < tree.size ())
      que.push (rightChild);
  }
  printf ("\n");

  return 0;
}