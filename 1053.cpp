#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Node
{
  bool leaf = true;
  int weight;
  int sum = 0;
  int parent;
};

void computeSum (vector<Node> &node, int req)
{
  if (!node[req].sum)
  {
    int parent = node[req].parent;
    computeSum (node, parent);
    node[req].sum = node[parent].sum + node[req].weight;
  }
}

int main ()
{
  int nodeNum, nonleafNum, reqWeight;
  scanf ("%d %d %d", &nodeNum, &nonleafNum, &reqWeight);

  vector<Node> node (nodeNum);
  for (int i = 0; i < nodeNum; ++i)
    scanf ("%d", &node[i].weight);

  node[0].parent = -1;
  for (int i = 0; i < nonleafNum; ++i)
  {
    int parent, childNum;
    scanf ("%d %d", &parent, &childNum);
    node[parent].leaf = false;

    for (int j = 0; j < childNum; ++j)
    {
      int child;
      scanf ("%d", &child);
      node[child].parent = parent;
    }
  }

  node[0].sum = node[0].weight;
  for (int i = 0; i < nodeNum; ++i)
    computeSum (node, i);

  vector<list<int>*> path;
  for (int i = 0; i < nodeNum; ++i)
  {
    if (node[i].leaf && node[i].sum == reqWeight)
    {
      path.push_back (new list<int> ());

      int ite = i;
      while (ite != -1)
      {
        path.back ()->push_front (node[ite].weight);
        ite = node[ite].parent;
      }
    }
  }

  auto pathCmp = [](const list<int> *lis1, const list<int> *lis2)->bool
  {
    auto ite1 = lis1->begin (), ite2 = lis2->begin ();
    while (ite1 != lis1->end () && ite2 != lis2->end ())
    {
      if (*ite1 != *ite2)
        return *ite1 > *ite2;
      else
      {
        ++ite1;
        ++ite2;
      }
    }

    return false;
  };
  sort (path.begin (), path.end (), pathCmp);

  for (auto &i : path)
  {
    auto ite = i->begin ();
    while (1)
    {
      printf ("%d", *ite);
      if (++ite != i->end ())
        printf (" ");
      else
      {
        printf ("\n");
        break;
      }
    }

    delete i;
  }

  return 0;
}