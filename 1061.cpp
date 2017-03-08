#include <cstdio>
#include <cctype>

int main ()
{
  char str1[61], str2[61], str3[61], str4[61];
  scanf ("%s %s %s %s", str1, str2, str3, str4);

  bool hour = false;
  for (int i = 0;; ++i)
  {
    if (str1[i] == str2[i])
    {
      char ch = str1[i];
      if (hour && ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'N')))
      {
        if (ch >= '0' && ch <= '9')
          printf ("%02d:", ch - '0');
        else
          printf ("%02d:", ch - 'A' + 10);

        break;
      }
      else if (!hour && ch >= 'A' && ch <= 'G')
      {
        char *day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
        printf ("%s ", day[ch - 'A']);
        hour = true;
      }
    }
  }

  for (int i = 0;; ++i)
  {
    if (str3[i] == str4[i] && isalpha (str3[i]))
    {
      printf ("%02d\n", i);
      break;
    }
  }

  return 0;
}