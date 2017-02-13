#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Record
{
  std::string name;
  std::string passwd;
  bool modified = false;
};

int main ()
{
  int recNum;
  scanf ("%d", &recNum);

  std::vector<Record> rec (recNum);
  for (int i = 0; i < recNum; ++i)
  {
    std::cin >> rec[i].name >> rec[i].passwd;
    for (auto &j : rec[i].passwd)
    {
      switch (j)
      {
        case '1':
          j = '@';
          rec[i].modified = true;
          break;

        case '0':
          j = '%';
          rec[i].modified = true;
          break;

        case 'l':
          j = 'L';
          rec[i].modified = true;
          break;

        case 'O':
          j = 'o';
          rec[i].modified = true;
          break;
      }
    }
  }

  int cnt = (int)std::count_if (rec.begin (), rec.end (), [](const Record &rec) { return rec.modified; });
  if (!cnt)
  {
    if (recNum > 1)
      printf ("There are %d accounts and no account is modified\n", recNum);
    else
      printf ("There is 1 account and no account is modified\n");
  }
  else
  {
    printf ("%d\n", cnt);
    for (auto &i : rec)
    {
      if (i.modified)
        printf ("%s %s\n", i.name.c_str (), i.passwd.c_str ());
    }
  }

  return 0;
}