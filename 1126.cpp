#include <cstdio>
#include <vector>

using namespace std;

struct Node
{
  int degree = 0;
  bool visit = false;
};

void DFS (vector<vector<int>> &graph, vector<Node> &node, int root)
{
  if (!node[root].visit)
  {
    node[root].visit = true;
    for (int i = 0; i < (int)graph.size (); ++i)
    {
      if (graph[root][i])
        DFS (graph, node, i);
    }
  }
}

int main ()
{
  int nodeNum, roadNum;
  scanf ("%d %d", &nodeNum, &roadNum);

  vector<vector<int>> graph (nodeNum);
  for (auto &i : graph)
    i.resize (nodeNum);

  vector<Node> node (nodeNum);
  for (int i = 0; i < roadNum; ++i)
  {
    int nodeA, nodeB;
    scanf ("%d %d", &nodeA, &nodeB);

    --nodeA; --nodeB;
    graph[nodeA][nodeB] = graph[nodeB][nodeA] = 1;

    node[nodeA].degree++;
    node[nodeB].degree++;
  }

  int odd = 0, even = 0;
  for (auto &i : node)
  {
    if (i.degree % 2)
      ++odd;
    else
      ++even;
  }

  for (int i = 0; i < nodeNum; ++i)
  {
    if (i)
      printf (" ");
    printf ("%d", node[i].degree);
  }
  printf ("\n");

  for (int i = 0; i < nodeNum; ++i)
  {
    if (node[i].degree)
    {
      DFS (graph, node, i);
      break;
    }
  }

  int i;
  for (i = 0; i < nodeNum; ++i)
  {
    if (node[i].degree && !node[i].visit)
      break;
  }

  if (i != nodeNum)
    printf ("Non-Eulerian\n");
  else
  {
    if (even == nodeNum)
      printf ("Eulerian\n");
    else if (odd == 2)
      printf ("Semi-Eulerian\n");
    else
      printf ("Non-Eulerian\n");
  }

  return 0;
}