#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime (int num)
{
  if (num == 2)
    return true;
  else
  {
    for (int i = 2; i <= sqrt (num); ++i)
    {
      if (num % i == 0)
        return false;
    }

    return true;
  }
}

int main ()
{
  int stuNum;
  scanf ("%d", &stuNum);

  vector<int> stu (10000, -1);
  for (int i = 0; i < stuNum; ++i)
  {
    int ID;
    scanf ("%d", &ID);
    stu[ID] = i + 1;
  }

  int reqNum;
  scanf ("%d", &reqNum);

  for (int i = 0; i < reqNum; ++i)
  {
    int ID;
    scanf ("%d", &ID);

    printf ("%04d: ", ID);
    if (stu[ID] == -1)
      printf ("Are you kidding?");
    else if (stu[ID] == 0)
      printf ("Checked");
    else 
    {
      if (stu[ID] == 1)
        printf ("Mystery Award");
      else if (isPrime (stu[ID]))
        printf ("Minion");
      else
        printf ("Chocolate");

      stu[ID] = 0;
    }
    printf ("\n");
  }

  return 0;
}