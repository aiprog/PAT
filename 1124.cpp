#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main ()
{
  int personNum, skipNum, startIndex;
  cin >> personNum >> skipNum >> startIndex;
  --startIndex;

  vector<string> person (personNum);
  for (auto &i : person)
    cin >> i;

  set<string> winner;
  while (startIndex < personNum)
  {
    if (winner.find (person[startIndex]) == winner.end ())
    {
      cout << person[startIndex] << endl;
      winner.insert (person[startIndex]);
      startIndex += skipNum;
    }
    else
      ++startIndex;
  }

  if (winner.empty ())
    cout << "Keep going...\n";

  return 0;
}