#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person
{
  string ID;
  int virtue;
  int talent;
  int type;
};

int main ()
{
  int personNum, low, high;
  scanf ("%d %d %d", &personNum, &low, &high);

  vector<Person> person;
  person.reserve (personNum);

  for (int i = 0; i < personNum; ++i)
  {
    string ID;
    int virtue, talent;

    char buf[10];
    scanf ("%s %d %d", buf, &virtue, &talent);
    ID = buf;

    if (virtue >= low && talent >= low)
    {
      int type;
      if (virtue >= high && talent >= high)
        type = 3;
      else if (virtue >= high)
        type = 2;
      else if (talent < high && virtue >= talent)
        type = 1;
      else
        type = 0;

      person.push_back ({ ID, virtue, talent, type });
    }
  }

  auto personCmp = [](const Person &p1, const Person &p2)->bool
  {
    if (p1.type != p2.type)
      return p1.type > p2.type;
    else if (p1.virtue + p1.talent != p2.virtue + p2.talent)
      return p1.virtue + p1.talent > p2.virtue + p2.talent;
    else if (p1.virtue != p2.virtue)
      return p1.virtue > p2.virtue;
    else
      return p1.ID < p2.ID;
  };
  sort (person.begin (), person.end (), personCmp);

  printf ("%d\n", (int)person.size ());
  for (auto &i : person)
    printf ("%s %d %d\n", i.ID.c_str (), i.virtue, i.talent);

  return 0;
}