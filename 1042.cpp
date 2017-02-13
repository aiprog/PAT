#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
  int card;
  int pos;
};

int main ()
{
  std::vector<Node> info (54);
  for (int i = 0; i < 54; ++i)
    info[i] = { i, 0 };

  int times;
  std::cin >> times;

  std::vector<int> pos (54);
  for (int i = 0; i < 54; ++i)
    std::cin >> pos[i];

  for (int i = 0; i < times; ++i)
  {
    for (int j = 0; j < 54; ++j)
      info[j].pos = pos[j];

    auto infoCmp = [](const Node &nA, const Node &nB) { return nA.pos < nB.pos; };
    std::sort (info.begin (), info.end (), infoCmp);
  }

  for (int i = 0; i < 54; ++i)
  {
    char *type = "SHCDJ";
    std::cout << type[info[i].card / 13] << info[i].card % 13 + 1;
    if (i != 53)
      std::cout << " ";
  }
  std::cout << std::endl;

  return 0;
}