#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main ()
{
  int segNum;
  std::cin >> segNum;

  std::vector<std::string> seg (segNum);
  for (int i = 0; i < segNum; ++i)
    std::cin >> seg[i];

  auto segCmp = [](const std::string &sA, const std::string &sB) { return sA + sB < sB + sA; };
  std::sort (seg.begin (), seg.end (), segCmp);

  std::string res;
  for (auto &i : seg)
    res.append (i);

  auto pos = res.find_first_not_of ('0');
  if (pos == std::string::npos)
    pos = res.size ();

  res.erase (res.begin (), res.begin () + pos);
  if (!res.size ())
    std::cout << "0";
  else
    std::cout << res;
  std::cout << std::endl;

  return 0;
}