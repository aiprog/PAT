#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Stu
{
  string name;
  int height;
};

int main ()
{
  int num, row;
  scanf ("%d %d", &num, &row);

  vector<Stu> stu (num);
  for (auto &i : stu)
    cin >> i.name >> i.height;

  auto stuCmp = [](Stu &sA, Stu &sB)
  {
    if (sA.height != sB.height)
      return sA.height > sB.height;
    else
      return sA.name < sB.name;
  };
  sort (stu.begin (), stu.end (), stuCmp);

  int index = 0;
  for (int i = 0; i < row; ++i)
  {
    int cnt = num / row;
    if (!i)
      cnt = num - (cnt * (row - 1));

    list<Stu> lis;
    int pos = 1;

    for (int j = 0; j < cnt; ++j, ++index)
    {
      if (!j)
        lis.push_back (stu[index]);
      else
      {
        if (!pos)
          lis.push_front (stu[index]);
        else
          lis.push_back (stu[index]);
      }

      pos = !pos;
    }

    for (auto ite = lis.begin (); ite != lis.end (); ++ite)
    {
      if (ite != lis.begin ())
        printf (" ");
      printf ("%s", ite->name.c_str ());
    }
    printf ("\n");
  }

  return 0;
}