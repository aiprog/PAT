#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int main ()
{
  int capacity, len, reqNum;
  scanf ("%d %d %d", &capacity, &len, &reqNum);

  for (int i = 0; i < reqNum; ++i)
  {
    vector<int> req (len);
    for (int j = 0; j < len; ++j)
      scanf ("%d", &req[j]);

    int ite = 1;
    stack<int> st;

    bool flag = true;
    for (auto &j : req)
    {
      if (j < ite)
      {
        if (!st.empty () && st.top () == j)
          st.pop ();
        else
        {
          flag = false;
          break;
        }
      }
      else
      {
        while (ite != j)
          st.push (ite++);

        if (st.size () + 1 > capacity)
        {
          flag = false;
          break;
        }
        else
          ++ite;
      }
    }

    if (flag)
      printf ("YES\n");
    else
      printf ("NO\n");
  }

  return 0;
}