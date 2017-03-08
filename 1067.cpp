#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
  int num;
  scanf ("%d", &num);

  vector<int> arr (num), flag (num);
  for (int i = 0; i < num; ++i)
    scanf ("%d", &arr[i]);

  int loop = 0, cnt = 0;
  if (arr[0] == 0)
  {
    ++loop;
    ++cnt;
  }

  for (int i = 0; i < num; ++i)
  {
    if (!flag[i] && arr[i] != i)
    {
      for (int j = i; !flag[j]; j = arr[j])
      {
        ++cnt;
        flag[j] = 1;
      }
      ++loop;
    }
  }
  printf ("%d\n", loop + cnt - 2);

  return 0;
}