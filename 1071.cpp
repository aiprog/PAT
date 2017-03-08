#include <cstdio>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main ()
{
  string text;
  getline (cin, text);

  for (auto &i : text)
  {
    if (isalnum (i))
      i = (char)tolower (i);
    else
      i = ' ';
  }

  istringstream strin (text);
  string word;
  map<string, int> cnt;

  while (strin >> word)
    ++cnt[word];

  vector<pair<string, int>> pvec (cnt.begin (), cnt.end ());
  auto pairCmp = [](const pair<string, int> &pA, const pair<string, int> &pB)
  {
    if (pA.second != pB.second)
      return pA.second > pB.second;
    else
      return pA.second < pB.second;
  };
  sort (pvec.begin (), pvec.end (), pairCmp);

  int max = pvec[0].second;
  for (auto i = 0; i < pvec.size () && pvec[i].second == max; ++i)
    cout << pvec[i].first << " " << max << endl;

  return 0;
}