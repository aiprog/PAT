#include <cstdio>
#include <vector>

using namespace std;

int main ()
{
  int num;
  scanf ("%d", &num);

  vector<double> arr (num);
  for (auto &i : arr)
    scanf ("%lf", &i);

  double sum = 0;
  for (int i = 0; i < num; ++i)
    sum += arr[i] * (i + 1) * (num - i);
  printf ("%.2lf\n", sum);

  return 0;
}