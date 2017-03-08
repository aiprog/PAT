#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stu
{
  string name;
  string ID;
};

int main ()
{
  int stuNum;
  scanf ("%d", &stuNum);

  vector<Stu> stu (101);
  for (int i = 0; i < stuNum; ++i)
  {
    string name, ID;
    int grade;

    cin >> name >> ID >> grade;
    stu[grade] = Stu { name, ID };
  }

  int beg, end;
  scanf ("%d %d", &beg, &end);

  bool none = true;
  for (int i = end; i != beg - 1; --i)
  {
    if (!stu[i].name.empty ())
    {
      printf ("%s %s\n", stu[i].name.c_str (), stu[i].ID.c_str ());
      none = false;
    }
  }

  if (none)
    printf ("NONE\n");

  return 0;
}