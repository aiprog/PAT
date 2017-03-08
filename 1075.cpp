#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Stu
{
  int ID = -1;
  vector<int> score;
  int sum = 0;
  int cnt = 0;
};

int main ()
{
  int stuNum, proNum, subNum;
  scanf ("%d %d %d", &stuNum, &proNum, &subNum);

  vector<int> score (proNum + 1);
  for (int i = 1; i <= proNum; ++i)
    scanf ("%d", &score[i]);

  vector<Stu> stu (100000);
  int validCnt = 0;

  for (int i = 0; i < subNum; ++i)
  {
    int ID, proID, grade;
    scanf ("%d %d %d", &ID, &proID, &grade);

    Stu &person = stu[ID];
    if (grade != -1 && person.ID == -1)
    {
      person.ID = ID;
      ++validCnt;
    }

    if (grade == -1)
      grade = 0;

    if (person.score.empty ())
      person.score.resize (proNum + 1, -1);

    if (person.score[proID] != -1)
      person.sum -= person.score[proID];
    if (grade > person.score[proID])
    {
      person.score[proID] = grade;
      if (grade == score[proID])
        ++person.cnt;
    }
    person.sum += person.score[proID];
  }

  vector<Stu> validStu (validCnt);
  copy_if (stu.begin (), stu.end (), validStu.begin (), [](const Stu &stu) { return stu.ID != -1; });

  auto stuCmp = [](const Stu &sA, const Stu &sB)
  {
    if (sA.sum != sB.sum)
      return sA.sum > sB.sum;
    else if (sA.cnt != sB.cnt)
      return sA.cnt > sB.cnt;
    else
      return sA.ID < sB.ID;
  };
  sort (validStu.begin (), validStu.end (), stuCmp);

  int curSum = -1, curRank = 1;
  for (int i = 0; i < validStu.size (); ++i)
  {
    Stu &person = validStu[i];
    if (person.sum != curSum)
    {
      curSum = person.sum;
      curRank = i + 1;
    }

    printf ("%d %05d %d", curRank, person.ID, person.sum);
    for (int j = 1; j <= proNum; ++j)
    {
      if (person.score[j] != -1)
        printf (" %d", person.score[j]);
      else
        printf (" -");
    }
    printf ("\n");
  }

  return 0;
}