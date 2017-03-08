#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void printVec (vector<int> &init)
{
  for (int i = 0; i < init.size (); ++i)
  {
    if (i)
      printf (" ");
    printf ("%d", init[i]);
  }
  printf ("\n");
}

int main ()
{
  int valNum;
  scanf ("%d", &valNum);

  vector<int> init (valNum), backup (valNum);
  for (auto &i : init)
    scanf ("%d", &i);
  backup = init;

  vector<int> part (valNum);
  for (auto &i : part)
    scanf ("%d", &i);

  bool flag = false;
  for (int i = 1; i < valNum; ++i)
  {
    int tmp = init[i], j = i;
    while (j && init[j - 1] > tmp)
    {
      init[j] = init[j - 1];
      --j;
    }
    init[j] = tmp;

    if (flag)
      break;
    else if (init == part)
      flag = true;
  }

  if (flag)
  {
    printf ("Insertion Sort\n");
    printVec (init);
  }
  else
  {
    init = backup;
    make_heap (init.begin (), init.end ());

    for (auto ite = init.end ();; --ite)
    {
      pop_heap (init.begin (), ite);
      if (flag)
        break;
      else if (init == part)
        flag = true;
    }

    printf ("Heap Sort\n");
    printVec (init);
  }

  return 0;
}