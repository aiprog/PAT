#include <cstdio>

int main ()
{
  char buf[100001];
  scanf ("%s", buf);

  int cnt[3] = { 0, 0, 0 };
  for (int i = 0; buf[i]; ++i)
  {
    switch (buf[i])
    {
      case 'P':
        cnt[0] = (cnt[0] + 1) % 1000000007;
        break;
      case 'A':
        cnt[1] = (cnt[1] + cnt[0]) % 1000000007;
        break;
      case 'T':
        cnt[2] = (cnt[2] + cnt[1]) % 1000000007;
        break;
    }
  }
  printf ("%d\n", cnt[2]);

  return 0;
}