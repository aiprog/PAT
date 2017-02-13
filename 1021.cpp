#include <cstdio>
#include <vector>
#include <list>

struct Node
{
  bool visit = false;
  std::list<int> node;
};

int DFS (std::vector<Node> &graph, int root)
{
  graph[root].visit = true;

  if (!graph[root].node.size ())
    return 1;
  else
  {
    int maxDeepth = 1;
    for (auto &i : graph[root].node)
    {
      if (!graph[i].visit)
      {
        int tmp = DFS (graph, i);
        if (tmp > maxDeepth)
          maxDeepth = tmp;
      }
    }

    return maxDeepth + 1;
  }
}

int main ()
{
  int nodeNum;
  scanf ("%d", &nodeNum);

  std::vector<Node> graph;
  graph.resize (nodeNum + 1);

  for (int i = 1; i < nodeNum; ++i)
  {
    int src, dst;
    scanf ("%d %d", &src, &dst);

    graph[src].node.push_back (dst);
    graph[dst].node.push_back (src);
  }

  int compNum = 0;
  for (int i = 1; i <= nodeNum; ++i)
  {
    if (!graph[i].visit)
    {
      ++compNum;
      DFS (graph, i);
    }
  }

  if (compNum > 1)
    printf ("Error: %d components\n", compNum);
  else
  {
    std::list<int> root;
    int maxDepth;

    for (int i = 1; i <= nodeNum; ++i)
    {
      for (auto &i : graph)
        i.visit = false;

      if (graph[i].node.size () <= 1)
      {
        int tmp = DFS (graph, i);
        if (!root.size () || tmp > maxDepth)
        {
          root.clear ();
          root.push_back (i);
          maxDepth = tmp;
        }
        else if (tmp == maxDepth)
          root.push_back (i);
      }
    }

    for (auto i : root)
      printf ("%d\n", i);
  }

  return 0;
}