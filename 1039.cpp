#include <cstdio>
#include <vector>
#include <algorithm>

int str2Int (char *name)
{
  return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + name[3] - '0';
}

std::vector<int> info[26 * 26 * 26 * 10];

int main ()
{
  int reqNum, courseNum;
  scanf ("%d %d", &reqNum, &courseNum);

  for (int i = 0; i < courseNum; ++i)
  {
    int courseIndex, stuNum;
    scanf ("%d %d", &courseIndex, &stuNum);

    for (int i = 0; i < stuNum; ++i)
    {
      char name[5];
      scanf ("%s", name);
      info[str2Int (name)].push_back (courseIndex);
    }
  }

  for (int i = 0; i < reqNum; ++i)
  {
    char name[5];
    scanf ("%s", name);

    int num = str2Int (name);
    std::sort (info[num].begin (), info[num].end ());

    printf ("%s %llu", name, info[num].size ());
    for (auto &i : info[num])
      printf (" %d", i);
    printf ("\n");
  }

  return 0;
}