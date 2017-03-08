#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Car
{
  int time;
  int cnt = 0;
};

struct Rec
{
  string name;
  int type;
  int time;
};

int main ()
{
  int recNum, reqNum;
  scanf ("%d %d", &recNum, &reqNum);

  vector<Rec> rec (recNum);
  for (auto &i : rec)
  {
    char name[10], op[5];
    int h, m, s;
    scanf ("%s %d:%d:%d %s", name, &h, &m, &s, op);
    
    int type = 0;
    if (!strcmp (op, "out"))
      type = 1;

    i = Rec { name, type, h * 3600 + m * 60 + s };
  }

  auto nameCmp = [](const Rec &rA, const Rec &rB)
  {
    if (rA.name != rB.name)
      return rA.name < rB.name;
    else
      return rA.time < rB.time;
  };
  sort (rec.begin (), rec.end (), nameCmp);

  vector<Rec> recTmp;
  for (auto &i : rec)
  {
    if (recTmp.empty ())
    {
      if (i.type == 0)
        recTmp.push_back (i);
    }
    else if (recTmp.back ().name == i.name)
    {
      if (recTmp.back ().type == 0)
      {
        if (i.type == 0)
          recTmp.pop_back ();
        recTmp.push_back (i);
      }
      else if (i.type == 0)
        recTmp.push_back (i);
    }
    else
    {
      if (recTmp.back ().type == 0)
        recTmp.pop_back ();

      if (i.type == 0)
        recTmp.push_back (i);
    }
  }
  if (recTmp.back ().type == 0)
    recTmp.pop_back ();

  rec = recTmp;
  recTmp.clear ();

  auto timeCmp = [](const Rec &rA, const Rec &rB) { return rA.time < rB.time; };
  sort (rec.begin (), rec.end (), timeCmp);

  vector<int> req (reqNum);
  for (auto &i : req)
  {
    int h, m, s;
    scanf ("%d:%d:%d", &h, &m, &s);
    i = h * 3600 + m * 60 + s;
  }

  map<string, Car> car;
  auto iteRec = rec.begin ();
  auto iteReq = req.begin ();
  int num = 0;

  while (iteRec != rec.end () || iteReq != req.end ())
  {
    if (iteReq == req.end () || (iteRec != rec.end () && iteRec->time <= *iteReq))
    {
      if (iteRec->type == 0)
      {
        car[iteRec->name].time = iteRec->time;
        ++num;
      }
      else
      {
        auto &info = car[iteRec->name];
        info.cnt += iteRec->time - info.time;
        --num;
      }
      ++iteRec;
    }
    else
    {
      printf ("%d\n", num);
      ++iteReq;
    }
  }

  vector<string> name;
  int max;

  for (auto &i : car)
  {
    if (name.empty () || i.second.cnt > max)
    {
      name.clear ();
      name.push_back (i.first);
      max = i.second.cnt;
    }
    else if (i.second.cnt == max)
      name.push_back (i.first);
  }

  sort (name.begin (), name.end ());
  for (auto &i : name)
    cout << i << " ";
  printf ("%02d:%02d:%02d\n", max / 3600, max % 3600 / 60, max % 60);

  return 0;
}