#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <algorithm>

struct Record
{
  int month;
  int day;
  int hour;
  int minute;
  std::string status;
}; 

int main ()
{
  int rate[24];
  for (int i = 0; i < 24; ++i)
    scanf ("%d", &rate[i]);

  int feePerDay = 0;
  for (auto i : rate)
    feePerDay += i;
  feePerDay *= 60;

  std::map<std::string, std::vector<Record>> info;
  int recNum;

  scanf ("%d", &recNum);
  for (int i = 0; i < recNum; ++i)
  {
    std::string name, status;
    int month, day, hour, minute;

    std::cin >> name;
    scanf ("%d:%d:%d:%d", &month, &day, &hour, &minute);
    std::cin >> status;

    info[name].push_back ({ month, day, hour, minute, status });
  }

  for (auto &i : info)
  {
    auto recCmp = [](const Record &r1, const Record &r2)
    { return r1.day < r2.day || (r1.day == r2.day && r1.hour < r2.hour) ||
      (r1.day == r2.day && r1.hour == r2.hour && r1.minute < r2.minute); };
    std::sort (i.second.begin (), i.second.end (), recCmp);

    std::list<Record> recList (i.second.begin (), i.second.end ());
    if (!recList.empty ())
    {
      auto pre = recList.begin (), cur = pre;
      ++cur;

      while (cur != recList.end ())
      {
        if (pre->status == "on-line" && cur->status == "off-line")
        {
          ++cur;
          if (cur != recList.end ())
          {
            std::advance (pre, 2);
            std::advance (cur, 1);
          }
          else
            pre = cur;
        }
        else
        {
          recList.erase (pre);
          pre = cur;
          ++cur;
        }
      }

      if (pre != recList.end ())
        recList.erase (pre);
    }

    if (!recList.empty ())
    {
      printf ("%s %02d\n", i.first.c_str (), recList.begin ()->month);

      int totalFee = 0;
      for (auto ite = recList.begin (); ite != recList.end (); ++ite)
      {
        int dayBeg = ite->day, hourBeg = ite->hour, minuteBeg = ite->minute;
        ++ite;
        int dayEnd = ite->day, hourEnd = ite->hour, minuteEnd = ite->minute;
        int duration = 0, dayFee, hourFee = 0, minuteFee;

        dayFee = (dayEnd - dayBeg) * feePerDay;
        duration += (dayEnd - dayBeg) * 24 * 60;

        for (int i = 0; i < hourBeg; ++i)
          hourFee -= rate[i] * 60;
        for (int i = 0; i < hourEnd; ++i)
          hourFee += rate[i] * 60;
        duration += (hourEnd - hourBeg) * 60;

        minuteFee = rate[hourEnd] * minuteEnd - rate[hourBeg] * minuteBeg;
        duration += minuteEnd - minuteBeg;

        int fee = dayFee + hourFee + minuteFee;
        printf ("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", dayBeg, hourBeg, minuteBeg,
          dayEnd, hourEnd, minuteEnd, duration, 1.0 * fee / 100);

        totalFee += fee;
      }
      printf ("Total amount: $%.2lf\n", 1.0 * totalFee / 100);
    }
  }

  return 0;
}