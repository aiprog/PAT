#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main ()
{
  int colorNum;
  scanf ("%d", &colorNum);
  vector<int> color2Index (colorNum + 1);

  int favorColorNum;
  scanf ("%d", &favorColorNum);
  vector<int> favorColor (favorColorNum + 1);

  for (int i = 1; i <= favorColorNum; ++i)
  {
    scanf ("%d", &favorColor[i]);
    color2Index[favorColor[i]] = i;
  }

  int stripeLen;
  scanf ("%d", &stripeLen);

  vector<pair<int, int>> stripe;
  int preColor = 0;
  int preCnt = 0;

  for (int i = 0; i < stripeLen; ++i)
  {
    int color;
    scanf ("%d", &color);

    if (color2Index[color])
    {
      if (color == preColor)
        ++preCnt;
      else
      {
        if (preCnt)
          stripe.push_back ({ preColor, preCnt });

        preColor = color;
        preCnt = 1;
      }
    }
  }

  if (color2Index[preColor])
    stripe.push_back ({ preColor, preCnt });

  vector<vector<int>> table (stripe.size ());
  for (auto &i : table)
    i.resize (favorColorNum + 1);

  for (int i = 0; i < stripe.size (); ++i)
  {
    int color = stripe[i].first;
    int cnt = stripe[i].second;
    int index = color2Index[color];

    if (i)
      table[i] = table[i - 1];

    auto ite = max_element (table[i].begin () + 1, table[i].begin () + index + 1);
    table[i][index] = *ite + cnt;
  }

  auto ite = max_element (table[stripe.size () - 1].begin (), table[stripe.size () - 1].end ());
  printf ("%d\n", *ite);

  return 0;
}