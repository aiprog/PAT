#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

void printZero (int num)
{
  while (num--)
    printf ("0");
}

int main ()
{
  char numSign, intPortion, fracPortion[10000];
  int exp;
  scanf ("%c%c.%[^E]E%d", &numSign, &intPortion, fracPortion, &exp);

  if (numSign == '-' && (intPortion != '0' || string (fracPortion).find_first_not_of ("0") != string::npos))
    printf ("%c", '-');
  
  if (exp < 0)
  {
    printf ("0.");
    printZero (-exp - 1);
    printf ("%c%s\n", intPortion, fracPortion);
  }
  else
  {
    printf ("%c", intPortion);
    int len = (int)strlen (fracPortion);
    if (exp < len)
    {
      char tmp = fracPortion[exp];
      fracPortion[exp] = '\0';
      printf ("%s.%c%s\n", fracPortion, tmp, fracPortion + exp + 1);
    }
    else
    {
      printf ("%s", fracPortion);
      if (exp > len)
        printZero (exp - len);
      printf ("\n");
    }
  }

  return 0;
}