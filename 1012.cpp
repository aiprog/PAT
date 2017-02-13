#include <cstdio>
#include <algorithm>

struct Record
{
  int ID;
  int score[4]; // Sum, C, math, English
  int rank = 0;
  int subject;
};

void computeRank (Record *rec, int recNum, int subject)
{
  int rank = 0, score = 301;
  for (int i = 0; i < recNum; ++i)
  {
    if (rec[i].score[subject] < score)
    {
      rank = i + 1;
      score = rec[i].score[subject];
    }

    if (rec[i].rank == 0 || rank < rec[i].rank)
    {
      rec[i].rank = rank;
      rec[i].subject = subject;
    }
  }
}

int main ()
{
  int recNum, reqNum;
  scanf ("%d %d", &recNum, &reqNum);

  Record *rec = new Record[recNum];
  for (int i = 0; i < recNum; ++i)
  {
    scanf ("%d %d %d %d", &rec[i].ID, &rec[i].score[1], &rec[i].score[2], &rec[i].score[3]);
    rec[i].score[0] = rec[i].score[1] + rec[i].score[2] + rec[i].score[3];
  }

  int *req = new int[reqNum];
  for (int i = 0; i < reqNum; ++i)
    scanf ("%d", &req[i]);

  for (int i = 0; i < 4; ++i)
  {
    auto scoreCmp = [i](const Record &r1, const Record &r2) { return r1.score[i] > r2.score[i]; };
    std::sort (rec, rec + recNum, scoreCmp);
    computeRank (rec, recNum, i);
  }

  auto IDCmp = [](const Record &r1, const Record &r2) { return r1.ID < r2.ID; };
  std::sort (rec, rec + recNum, IDCmp);

  for (int i = 0; i < reqNum; ++i)
  {
    Record tmp;
    tmp.ID = req[i];

    auto ptr = std::lower_bound (rec, rec + recNum, tmp, IDCmp);
    if (ptr != rec + recNum && ptr->ID == req[i])
    {
      char subject[4] = { 'A', 'C', 'M', 'E' };
      printf ("%d %c\n", ptr->rank, subject[ptr->subject]);
    }
    else
      printf ("N/A\n");
  }

  delete[] rec;
  delete[] req;

  return 0;
}