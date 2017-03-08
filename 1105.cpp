#include <cstdio>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main ()
{
  int num;
  scanf ("%d", &num);

  int row = (int)sqrt (num), col;
  while (num % row || row < num / row)
    ++row;
  col = num / row;

  vector<int> arr (num);
  for (auto &i : arr)
    scanf ("%d", &i);
  sort (arr.begin (), arr.end (), greater<int> ());

  vector<vector<int>> matrix (row);
  for (auto &i : matrix)
    i.resize (col);

  int rowIte = 0, colIte = 0, direction = 0;
  for (auto &i : arr)
  {
    matrix[rowIte][colIte] = i;
    switch (direction)
    {
      case 0:
        if (colIte != col - 1 && !matrix[rowIte][colIte + 1])
          ++colIte;
        else
        {
          ++rowIte;
          direction = 1;
        }

        break;
      case 1:
        if (rowIte != row - 1 && !matrix[rowIte + 1][colIte])
          ++rowIte;
        else
        {
          --colIte;
          direction = 2;
        }

        break;
      case 2:
        if (colIte && !matrix[rowIte][colIte - 1])
          --colIte;
        else
        {
          --rowIte;
          direction = 3;
        }

        break;
      case 3:
        if (rowIte && !matrix[rowIte - 1][colIte])
          --rowIte;
        else
        {
          ++colIte;
          direction = 0;
        }
    }
  }

  for (auto &i : matrix)
  {
    for (int j = 0; j < col; ++j)
    {
      if (j)
        printf (" ");
      printf ("%d", i[j]);
    }
    printf ("\n");
  }

  return 0;
}