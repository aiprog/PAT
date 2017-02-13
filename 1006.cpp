#include <cstdio>
#include <algorithm>
#include <functional>
#include <iostream>

struct Record
{
  char ID[16] = { 0 };
  int inTime;
  int outTime;
};

bool cmp (const Record &r1, const Record &r2, bool inTime)
{
  if (inTime)
    return r1.inTime <= r2.inTime;
  else
    return r1.outTime <= r2.outTime;
}

int main ()
{
  int num;
  scanf ("%d", &num);

  Record *rec = new Record[num];
  for (int i = 0; i < num; ++i)
  {
    scanf ("%s", rec[i].ID);

    int h, m, s;
    scanf ("%d:%d:%d", &h, &m, &s);
    rec[i].inTime = h * 3600 + m * 60 + s;
    scanf ("%d:%d:%d", &h, &m, &s);
    rec[i].outTime = h * 3600 + m * 60 + s;
  }

  std::sort (rec, rec + num, std::bind (cmp, std::placeholders::_1, std::placeholders::_2, true));
  printf ("%s ", rec[0].ID);

  std::sort (rec, rec + num, std::bind (cmp, std::placeholders::_1, std::placeholders::_2, false));
  printf ("%s\n", rec[num - 1].ID);

  delete[] rec;

  return 0;
}
