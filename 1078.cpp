#include <cstdio>
#include <vector>

using namespace std;

bool isPrime (int num)
{
  if (num == 1)
    return false;
  else if (num == 2)
    return true;
  else
  {
    for (int i = 2; i * i <= num; ++i)
    {
      if (num % i == 0)
        return false;
    }
  }

  return true;
}

int main ()
{
  int tableSz, valNum;
  scanf ("%d %d", &tableSz, &valNum);

  while (!isPrime (tableSz))
    ++tableSz;

  vector<int> hash (tableSz, -1);
  for (int i = 0; i < valNum; ++i)
  {
    int val;
    scanf ("%d", &val);

    if (i)
      printf (" ");

    int rem = val % tableSz;
    for (int j = 0;;)
    {
      
      int slot = (rem + j * j) % tableSz;
      if (hash[slot] == -1)
      {
        hash[slot] = val;
        printf ("%d", slot);
        break;
      }
      else if (++j == tableSz)
      {
        printf ("-");
        break;
      }
    }
  }
  printf ("\n");

  return 0;
}