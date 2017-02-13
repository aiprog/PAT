#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student
{
  std::string ID;
  int score;
  int placeNum;
};

int main ()
{
  int placeNum;
  scanf ("%d", &placeNum);

  std::vector<Student> student;
  for (int i = 0; i < placeNum; ++i)
  {
    int studentNum;
    scanf ("%d", &studentNum);

    for (int j = 0; j < studentNum; ++j)
    {
      std::string ID;
      int score;

      std::cin >> ID >> score;
      student.push_back ({ ID, score, i });
    }
  }

  auto studentCmp = [](const Student &s1, const Student &s2)
  { return s1.score > s2.score || (s1.score == s2.score && s1.ID < s2.ID); };
  std::sort (student.begin (), student.end (), studentCmp);

  std::vector<int> localNum (placeNum, 0), localScore (placeNum, -1), localRank (placeNum, 0);
  int finalScore = -1, finalRank = 0;

  printf ("%d\n", (int)student.size ());
  for (auto ite = student.begin (); ite != student.end (); ++ite)
  {
    if (ite->score != finalScore)
    {
      finalScore = ite->score;
      finalRank = (int)(ite - student.begin ()) + 1;
    }

    int placeNum = ite->placeNum;
    if (ite->score == localScore[placeNum])
      localNum[placeNum]++;
    else
    {
      localNum[placeNum]++;
      localScore[placeNum] = ite->score;
      localRank[placeNum] = localNum[placeNum];
    }

    printf ("%s %d %d %d\n", ite->ID.c_str (), finalRank, ite->placeNum + 1, localRank[placeNum]);
  }

  return 0;
}