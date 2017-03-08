#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
  int parent = -1;
  int cnt;
  int rank = 0;
};

void int2Pos (vector<vector<vector<Node>>> &arr, int nd, int &x, int &y, int &z)
{
  int row = (int)arr[0].size (), col = (int)arr[0][0].size ();
  x = nd / (row * col);
  y = nd % (row * col) / col;
  z = nd % (row * col) % col;
}

int pos2Int (vector<vector<vector<Node>>> &arr, int x, int y, int z)
{
  int row = (int)arr[0].size (), col = (int)arr[0][0].size ();
  return x * row * col + y * col + z;
}

int findSet (vector<vector<vector<Node>>> &arr, int nd)
{
  int x, y, z;
  int2Pos (arr, nd, x, y, z);

  int &parent = arr[x][y][z].parent;
  if (parent == -1)
    return nd;
  else
  {
    parent = findSet (arr, parent);
    return parent;
  }
}

void unionSet (vector<vector<vector<Node>>> &arr, int ndA, int ndB)
{
  ndA = findSet (arr, ndA), ndB = findSet (arr, ndB);
  if (ndA != ndB)
  {
    int xA, yA, zA, xB, yB, zB;
    int2Pos (arr, ndA, xA, yA, zA);
    int2Pos (arr, ndB, xB, yB, zB);

    if (arr[xA][yA][zA].rank < arr[xB][yB][zB].rank)
    {
      swap (ndA, ndB);
      swap (xA, xB);
      swap (yA, yB);
      swap (zA, zB);
    }

    arr[xB][yB][zB].parent = ndA;
    arr[xA][yA][zA].cnt += arr[xB][yB][zB].cnt;
    arr[xA][yA][zA].rank = max (arr[xA][yA][zA].rank, arr[xB][yB][zB].rank + 1);
  }
}

int main ()
{
  int row, col, height, threshold;
  scanf ("%d %d %d %d", &row, &col, &height, &threshold);

  vector<vector<vector<Node>>> arr (height);
  for (auto &i : arr)
  {
    i.resize (row);
    for (auto &j : i)
      j.resize (col);
  }

  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < row; ++j)
    {
      for (int k = 0; k < col; ++k)
        scanf ("%d", &arr[i][j][k].cnt);
    }
  }

  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < row; ++j)
      for (int k = 0; k < col; ++k)
      {
        if (i && arr[i][j][k].cnt && arr[i - 1][j][k].cnt)
          unionSet (arr, pos2Int (arr, i, j, k), pos2Int (arr, i - 1, j, k));

        if (j && arr[i][j][k].cnt && arr[i][j - 1][k].cnt)
          unionSet (arr, pos2Int (arr, i, j, k), pos2Int (arr, i, j - 1, k));

        if (k && arr[i][j][k].cnt && arr[i][j][k - 1].cnt)
          unionSet (arr, pos2Int (arr, i, j, k), pos2Int (arr, i, j, k - 1));
      }
  }

  int cnt = 0;
  for (auto &i : arr)
    for (auto &j : i)
      for (auto &k : j)
      {
        if (k.parent == -1 && k.cnt >= threshold)
          cnt += k.cnt;
      }
  printf ("%d\n", cnt);

  return 0;
}