#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int studentNum, courseNum;
  scanf ("%d %d", &studentNum, &courseNum);

  vector<vector<string>> course (courseNum + 1);
  for (int i = 0; i < studentNum; ++i)
  {
    string stu;
    cin >> stu;

    int selectNum;
    scanf ("%d", &selectNum);

    for (int i = 0; i < selectNum; ++i)
    {
      int selectCourse;
      scanf ("%d", &selectCourse);
      course[selectCourse].push_back (stu);
    }
  }

  for (int i = 1; i <= courseNum; ++i)
  {
    printf ("%d %d\n", i, (int)course[i].size ());
    sort (course[i].begin (), course[i].end ());
    for (auto &j : course[i])
      printf ("%s\n", j.c_str ());
  }

  return 0;
}