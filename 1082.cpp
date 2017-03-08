#include <cstdio>
#include <sstream>
#include <vector>

using namespace std;

struct Chinese
{
  int num;
  int weight;
  int power;
};

int main ()
{
  int num, sign = 0;
  scanf ("%d", &num);
  if (num < 0)
  {
    sign = 1;
    num = -num;
  }

  vector<int> digit (9);
  for (int i = 8; num; --i)
  {
    digit[i] = num % 10;
    num /= 10;
  }

  char *strA[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
  char *strB[4] = { "Qian", "Bai", "Shi", "Ge" };
  char *strC[3] = { "Yi", "Wan", "Ge" };
  vector<Chinese> lis;

  bool flag = false;
  for (int i = 0; i < 9; ++i)
  {
    if (digit[i])
    {
      lis.push_back ({ digit[i], (i + 3) % 4, (i + 3) / 4});
      flag = true;
    }

    if (i % 4 == 0)
    {
      if (flag)
        lis.push_back ({ -1, i / 4, (i + 3) / 4});
      flag = false;
    }
  }

  if (lis.empty ())
  {
    printf ("ling\n");
    return 0;
  }

  ostringstream strout;
  if (sign)
    strout << "Fu";
  else
    strout << "Zheng";

  for (auto ite = lis.begin (); ite != lis.end (); ++ite)
  {
    if (ite->num == -1)
    {
      if (ite->weight != 2)
      {
        strout << " " << strC[ite->weight];
        auto next = ite + 1;
        if (next != lis.end () && (next->weight != 0 || next->power != ite->power + 1))
          strout << " ling";
      }
    }
    else
    {
      strout << " " << strA[ite->num];
      if (ite->weight != 3)
        strout << " " << strB[ite->weight];

      auto next = ite + 1;
      if (next != lis.end () && next->num != -1 && next->weight != ite->weight + 1)
        strout << " ling";
    }
  }

  string str (strout.str ());
  if (str[0] != 'F')
    printf ("%s\n", str.c_str () + 6);
  else
    printf ("%s\n", str.c_str ());

  return 0;
}