#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <map>

using namespace std;

int str2Int (char *str)
{
  return (str[0] - 'a') * 26 * 26 + (str[1] - 'a') * 26 + str[2] - 'a';
}

int main ()
{
  char *strA[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
  char *strB[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

  map<string, pair<int, int>> str2Num;
  for (int i = 0; i < 13; ++i)
  {
    str2Num[string (strA[i])] = { 1, i };
    str2Num[string (strB[i])] = { 13, i };
  }

  int num;
  cin >> num;
  cin.get ();

  for (int i = 0; i < num; ++i)
  {
    string buf;
    getline (cin, buf);

    istringstream strIn (buf);
    if (isdigit (buf[0]))
    {
      int val;
      strIn >> val;

      if (val / 13)
      {
        printf ("%s", strB[val / 13]);
        if (val % 13)
          printf (" %s", strA[val % 13]);
      }
      else
        printf ("%s", strA[val % 13]);
      printf ("\n");
    }
    else
    {
      string val;
      int sum = 0;

      while (strIn >> val)
        sum += str2Num[val].first * str2Num[val].second;
      printf ("%d\n", sum);
    }
  }

  return 0;
}