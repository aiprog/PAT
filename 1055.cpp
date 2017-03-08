#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
  string name;
  int wealth;
};

int main ()
{
  int personNum, reqNum;
  scanf ("%d %d", &personNum, &reqNum);

  vector<vector<Person>> info (201);
  for (int i = 0; i < personNum; ++i)
  {
    string name;
    int age, wealth;
    
    cin >> name >> age >> wealth;
    info[age].push_back ({ name, wealth });
  }

  for (auto &i : info)
  {
    auto personCmp = [](const Person &p1, const Person &p2)
    {
      if (p1.wealth != p2.wealth)
        return p1.wealth > p2.wealth;
      else if (p1.name != p2.name)
        return p1.name < p2.name;
      else
        return false;
    };
    sort (i.begin (), i.end (), personCmp);
  }

  for (int i = 0; i < reqNum; ++i)
  {
    int num, minAge, maxAge;
    scanf ("%d %d %d", &num, &minAge, &maxAge);
    printf ("Case #%d:\n", i + 1);

    vector<int> ite (201);
    for (int j = 0; j < num; ++j)
    {
      int min = minAge;
      for (int k = minAge; k <= maxAge; ++k)
      {
        if (ite[k] != info[k].size ())
        {
          if (ite[min] == info[min].size () || info[k][ite[k]].wealth > info[min][ite[min]].wealth)
            min = k;
        }
      }

      if (min == minAge && ite[min] == info[min].size ())
      {
        if (!j)
          printf ("None\n");
        break;
      }
      else
      {
        Person &p = info[min][ite[min]];
        printf ("%s %d %d\n", p.name.c_str (), min, p.wealth);
        ++ite[min];
      }
    }
  }

  return 0;
}