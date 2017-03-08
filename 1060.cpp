#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

struct Resp
{
  string sig;
  int exp;
};

Resp getResp (string num, int digit)
{
  string sig (digit, '0');
  int exp;

  int dotPos = (int)num.find_first_of (".");
  if (dotPos == string::npos)
    dotPos = (int)num.size ();

  int nonZero = (int)num.find_first_not_of (".0");
  if (nonZero == string::npos)
    return { sig, 0 };

  if (dotPos >= nonZero)
    exp = dotPos - nonZero;
  else
    exp = dotPos - nonZero + 1;

  if (dotPos != num.size ())
    num.erase (num.begin () + dotPos);

  nonZero = (int)num.find_first_not_of ('0');
  if (nonZero == string::npos)
    nonZero = (int)num.size ();
  num.erase (num.begin (), num.begin () + nonZero);

  for (int i = 0; i != num.size () && digit; ++i, --digit)
    sig[i] = num[i];

  return { sig, exp };
}

int main ()
{
  int digit;
  string numA, numB;
  cin >> digit >> numA >> numB;

  Resp respA = getResp (numA, digit), respB = getResp (numB, digit);
  if (respA.sig == respB.sig && respA.exp == respB.exp)
    printf ("YES 0.%s*10^%d\n", respA.sig.c_str (), respA.exp);
  else
    printf ("NO 0.%s*10^%d 0.%s*10^%d\n", respA.sig.c_str (), respA.exp, respB.sig.c_str (), respB.exp);

  return 0;
}