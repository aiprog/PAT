#include <cstdio>
#include <cstring>

int cmp (char *numB, int lenB, long radixB, long valueA)
{
  long valueB = 0;
  for (int i = 0; i < lenB; ++i)
  {
    valueB = valueB * radixB + numB[i];
    if (valueB < 0 || valueB > valueA)
      return 1;
  }

  if (valueB == valueA)
    return 0;

  return -1;
}

int main ()
{
  char buf[11], numA[11], numB[11];
  long radixA, radixB, radixFlag, radixBeg, radixEnd, valueA;
  int lenA, lenB;

  scanf ("%s", buf);
  lenA = strlen (buf);

  for (int i = 0; buf[i]; ++i)
  {
    if (buf[i] >= 'a')
      numA[i] = 10 + buf[i] - 'a';
    else
      numA[i] = buf[i] - '0';
  }

  scanf ("%s", buf);
  lenB = strlen (buf);

  for (int i = 0; buf[i]; ++i)
  {
    if (buf[i] >= 'a')
      numB[i] = 10 + buf[i] - 'a';
    else
      numB[i] = buf[i] - '0';
  }

  scanf ("%ld %ld", &radixFlag, &radixA);
  if (radixFlag == 2)
  {
    memcpy (buf, numA, 11);
    memcpy (numA, numB, 11);
    memcpy (numB, buf, 11);

    int tmp = lenA;
    lenA = lenB;
    lenB = tmp;
  }

  valueA = 0;
  for (int i = 0; i < lenA; ++i)
    valueA = valueA * radixA + numA[i];

  radixBeg = 2;
  for (int i = 0; i < lenB; ++i)
    if (numB[i] + 1 > radixBeg)
      radixBeg = numB[i] + 1;

  radixEnd = radixBeg;
  while (cmp (numB, lenB, radixEnd, valueA) == -1)
    radixEnd *= 2;

  radixB = -1;
  while (radixBeg <= radixEnd)
  {
    if (cmp (numB, lenB, radixBeg, valueA) == 1 || cmp (numB, lenB, radixEnd, valueA) == -1)
      break;

    long radixMid = (radixBeg + radixEnd) / 2;
    int tmp = cmp (numB, lenB, radixMid, valueA);

    if (tmp == -1)
      radixBeg = radixMid + 1;
    else
    {
      if (tmp == 0 && (radixB == -1 || radixMid < radixB))
        radixB = radixMid;

      radixEnd = radixMid - 1;
    }
  }

  if (radixB != -1)
    printf ("%ld\n", radixB);
  else
    printf ("Impossible\n");

  return 0;
}
