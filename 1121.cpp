#include <cstdio>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

struct Person
{
  int partner = -1;
  bool present = false;
};

int main ()
{
  int coupleNum;
  scanf ("%d", &coupleNum);

  vector<Person> party (100000);
  for (int i = 0; i < coupleNum; ++i)
  {
    int personA, personB;
    scanf ("%d %d", &personA, &personB);

    party[personA].partner = personB;
    party[personB].partner = personA;
  }

  int personNum;
  scanf ("%d", &personNum);

  for (int i = 0; i < personNum; ++i)
  {
    int person;
    scanf ("%d", &person);
    party[person].present = true;
  }

  ostringstream strout;
  int cnt = 0;
  bool first = true;

  for (int i = 0; i < 100000; ++i)
  {
    if (party[i].present)
    {
      int partner = party[i].partner;
      if (partner == -1 || !party[partner].present)
      {
        if (!first)
          strout << " ";
        else
          first = false;
        strout << setw (5) << setfill ('0') << i;

        ++cnt;
      }
    }
  }

  printf ("%d\n", cnt);
  if (cnt)
    printf ("%s\n", strout.str ().c_str ());

  return 0;
}