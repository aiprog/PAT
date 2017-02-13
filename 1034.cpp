#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

struct Person
{
  bool visit = false;
  int weight = 0;
  std::list<int> relation;
};

struct Gang
{
  int memberNum;
  int head;
};

int str2Int (char *name)
{
  return (name[0] - 'A') * 26 * 26 + (name[1] - 'A') * 26 + name[2] - 'A';
}

void DFS (std::vector<Person> &graph, int root, int &weight, int &memberNum, int &head)
{
  graph[root].visit = true;
  weight += graph[root].weight;
  ++memberNum;
  if (head == -1 || graph[root].weight > graph[head].weight)
    head = root;

  for (auto &i : graph[root].relation)
  {
    if (!graph[i].visit)
      DFS (graph, i, weight, memberNum, head);
  }
}

int main ()
{
  int recNum, threadhold;
  scanf ("%d %d", &recNum, &threadhold);

  std::vector<Person> graph (26 * 26 * 26);
  for (int i = 0; i < recNum; ++i)
  {
    char strA[4], strB[4];
    int minute;
    scanf ("%s %s %d", strA, strB, &minute);

    int intA = str2Int (strA), intB = str2Int (strB);
    graph[intA].relation.push_back (intB);
    graph[intA].weight += minute;
    graph[intB].relation.push_back (intA);
    graph[intB].weight += minute;
  }

  std::vector<Gang> gang;
  for (int i = 0; i < graph.size (); ++i)
  {
    int weight = 0, memberNum = 0, head = -1;
    if (!graph[i].visit && !graph[i].relation.empty ())
    {
      DFS (graph, i, weight, memberNum, head);
      if (weight / 2 > threadhold && memberNum > 2)
        gang.push_back ({ memberNum, head });
    }
  }

  auto gangCmp = [](const Gang &gA, const Gang &gB) { return gA.head < gB.head; };
  std::sort (gang.begin (), gang.end (), gangCmp);

  printf ("%llu\n", gang.size ());
  for (auto &i : gang)
  {
    char name[4] = { 0 };
    name[0] = 'A' + i.head / (26 * 26);
    name[1] = 'A' + i.head / 26 % 26;
    name[2] = 'A' + i.head % 26;
    printf ("%s %d\n", name, i.memberNum);
  }

  return 0;
}