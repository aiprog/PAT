#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using STU = std::vector<std::string>;

int main ()
{
  int stuNum, column;
  scanf ("%d %d", &stuNum, &column);

  std::vector<STU> rec (stuNum);
  for (int i = 0; i < stuNum; ++i)
  {
    rec[i].resize (3);
    char info[3][10];

    scanf ("%s %s %s", info[0], info[1], info[2]);
    for (int j = 0; j < 3; ++j)
      rec[i][j] = info[j];
  }

  --column;
  auto stuCmp = [column](const STU &s1, const STU &s2)
  { return s1[column] < s2[column] || (s1[column] == s2[column] && s1[0] < s2[0]); };
  std::sort (rec.begin (), rec.end (), stuCmp);

  for (auto i : rec)
    printf ("%s %s %s\n", i[0].c_str (), i[1].c_str (), i[2].c_str ());

  return 0;
}