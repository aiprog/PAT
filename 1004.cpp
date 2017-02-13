#include <cstdio>
#include <cstring>

typedef struct _info
{
  bool leaf = true;
  int parent = -1;
  int level = -1;
} Info;

void computeLevel (Info *tree, int node)
{
  if (tree[node].level == -1)
  {
    computeLevel (tree, tree[node].parent);
    tree[node].level = tree[tree[node].parent].level + 1;
  }
}

int main ()
{
  int node, nonleaf;
  scanf ("%d %d", &node, &nonleaf);

  Info *tree = new Info[node + 1];
  for (int i = 0; i < nonleaf; ++i)
  {
    int parent, num;
    scanf ("%d %d", &parent, &num);
    tree[parent].leaf = false;

    for (int j = 0; j < num; ++j)
    {
      int child;
      scanf ("%d", &child);
      tree[child].parent = parent;
    }
  }

  tree[1].level = 0;
  for (int i = 2; i <= node; ++i)
    computeLevel(tree, i);

  int level = 0;
  for (int i = 2; i <= node; ++i)
    if (tree[i].level > level)
      level = tree[i].level;

  int *leaf = new int[level + 1];
  memset (leaf, 0, (level + 1) * sizeof (int));

  for (int i = 1; i <= node; ++i)
  {
    if (tree[i].leaf)
      ++leaf[tree[i].level];
  }

  printf ("%d", leaf[0]);
  for (int i = 1; i <= level; ++i)
    printf (" %d", leaf[i]);
  printf ("\n");

  delete[] tree;
  delete[] leaf;

  return 0;
}
