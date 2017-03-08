#include <cstdio>
#include <cstring>
#include <stack>
#include <set>

using namespace std;

void balanceSet (multiset<int> &left, multiset<int> &right)
{
  if (left.size () < right.size ())
  {
    auto rMin = right.begin ();
    left.insert (*rMin);
    right.erase (rMin);
  }
  else if (left.size () > right.size () + 1)
  {
    auto lMax = left.end ();
    --lMax;
    right.insert (*lMax);
    left.erase (lMax);
  }
}

int main ()
{
  int opNum;
  scanf ("%d", &opNum);

  stack<int> st;
  multiset<int> left, right;

  for (int i = 0; i < opNum; ++i)
  {
    char op[15];
    scanf ("%s", op);

    if (!strcmp (op, "Push"))
    {
      int num;
      scanf ("%d", &num);
      st.push (num);

      if (left.empty () && right.empty ())
        left.insert (num);
      else
      {
        if (right.empty ())
          left.insert (num);
        else
        {
          auto rMin = right.begin ();
          if (num >= *rMin)
            right.insert (num);
          else
            left.insert (num);
        }

        balanceSet (left, right);
      }
    }
    else if (!strcmp (op, "Pop"))
    {
      if (st.empty ())
        printf ("Invalid\n");
      else
      {
        int top = st.top ();
        printf ("%d\n", top);
        st.pop ();

        auto ite = left.find (top);
        if (ite != left.end ())
          left.erase (ite);
        else
          right.erase (right.find (top));

        balanceSet (left, right);
      }
    }
    else
    {
      if (left.empty ())
        printf ("Invalid\n");
      else
      {
        auto lMax = left.end ();
        --lMax;
        printf ("%d\n", *lMax);
      }
    }
  }

  return 0;
}