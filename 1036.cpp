#include <cstdio>
#include <iostream>
#include <string>

int main ()
{
  int num;
  scanf ("%d", &num);

  std::string nameM, IDM, nameF, IDF;
  int gradeM, gradeF;

  for (int i = 0; i < num; ++i)
  {
    std::string name, gender, ID;
    int grade;

    std::cin >> name >> gender >> ID >> grade;
    if (gender == "M")
    {
      if (nameM.empty () || grade < gradeM)
      {
        nameM = name;
        IDM = ID;
        gradeM = grade;
      }
    }
    else
    {
      if (nameF.empty () || grade > gradeF)
      {
        nameF = name;
        IDF = ID;
        gradeF = grade;
      }
    }
  }

  if (!nameF.empty ())
    printf ("%s %s\n", nameF.c_str (), IDF.c_str ());
  else
    printf ("Absent\n");

  if (!nameM.empty ())
    printf ("%s %s\n", nameM.c_str (), IDM.c_str ());
  else
    printf ("Absent\n");

  if (!nameM.empty () && !nameF.empty ())
    printf ("%d\n", gradeF - gradeM);
  else
    printf ("NA\n");

  return 0;
}