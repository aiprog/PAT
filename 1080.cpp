#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct School
{
  bool accept;
  int quota;
  vector<int> stu;
};

struct Student
{
  int ID;
  int entrance;
  int interview;
  vector<int> choice;
};

int main ()
{
  int stuNum, schNum, choiceNum;
  scanf ("%d %d %d", &stuNum, &schNum, &choiceNum);

  vector<School> school (schNum);
  for (int i = 0; i < schNum; ++i)
    scanf ("%d", &school[i].quota);

  vector<Student> student (stuNum);
  for (int i = 0; i < stuNum; ++i)
  {
    Student &stu = student[i];
    stu.choice.resize (choiceNum);

    stu.ID = i;
    scanf ("%d %d", &stu.entrance, &stu.interview);
    for (int j = 0; j < choiceNum; ++j)
      scanf ("%d", &stu.choice[j]);
  }

  auto stuCmp = [](const Student &stuA, const Student &stuB)->bool
  {
    int sumA = stuA.entrance + stuA.interview, sumB = stuB.entrance + stuB.interview;
    if (sumA != sumB)
      return sumA > sumB;
    else if (stuA.entrance != stuB.entrance)
      return stuA.entrance > stuB.entrance;
    else
      return false;
  };
  sort (student.begin (), student.end (), stuCmp);

  auto beg = student.begin (), end = student.begin ();
  while (end != student.end ())
  {
    beg = end;
    while (end != student.end () && end->entrance == beg->entrance && end->interview == beg->interview)
      ++end;

    for (auto &i : school)
    {
      if (i.stu.size () < i.quota)
        i.accept = true;
      else
        i.accept = false;
    }

    for (auto ite = beg; ite != end; ++ite)
    {
      for (auto &i : ite->choice)
      {
        if (school[i].accept)
        {
          school[i].stu.push_back (ite->ID);
          break;
        }
      }
    }
  }

  for (auto &i : school)
  {
    sort (i.stu.begin (), i.stu.end ());
    int first = true;
    for (auto &j : i.stu)
    {
      if (first)
        first = false;
      else
        printf (" ");
      printf ("%d", j);
    }
    printf ("\n");
  }

  return 0;
}
