#include <cstdio>

int main ()
{
  long long value[2];
  for (int i = 0; i < 2; ++i)
  {
    long long galleon, sickle, knut;
    scanf ("%lld.%lld.%lld", &galleon, &sickle, &knut);
    value[i] = galleon * 17 * 29 + sickle * 29 + knut;
  }

  long long sum = value[0] + value[1];
  printf ("%lld.%lld.%lld\n", sum / (17 * 29), sum % (17 * 29) / 29, sum % 29);

  return 0;
}