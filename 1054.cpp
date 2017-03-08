#include <cstdio>
#include <stack>

using namespace std;

int main ()
{
  int row, col;
  scanf ("%d %d", &row, &col);

  stack<int> st;
  for (int i = 0; i < row * col; ++i)
  {
    int color;
    scanf ("%d", &color);

    if (st.empty () || st.top () == color)
      st.push (color);
    else
      st.pop ();
  }
  printf ("%d\n", st.top ());

  return 0;
}