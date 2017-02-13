#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

struct Key
{
  int type;
  std::string str;
};

int main ()
{
  int bookNum;
  scanf ("%d", &bookNum);
  getchar ();

  auto keyCmp = [](const Key &k1, const Key &k2) 
  { return k1.type < k2.type || (k1.type == k2.type && k1.str < k2.str); };
  std::multimap<Key, std::string, decltype (keyCmp)> rec (keyCmp);

  for (int i = 0; i < bookNum; ++i)
  {
    std::string ID;
    std::string title, author, keyword, publisher, year;

    std::getline (std::cin, ID);
    std::getline (std::cin, title);
    std::getline (std::cin, author);
    std::getline (std::cin, keyword);
    std::getline (std::cin, publisher);
    std::getline (std::cin, year);

    rec.insert ({ { 1, title }, ID });
    rec.insert ({ { 2, author }, ID });
    rec.insert ({ { 4, publisher }, ID });
    rec.insert ({ { 5, year }, ID });

    std::istringstream istr (keyword);
    std::string tmp;

    while (istr >> tmp)
      rec.insert ({ { 3, tmp }, ID });
  }

  int queryNum;
  scanf ("%d", &queryNum);
  getchar ();

  for (int i = 0; i < queryNum; ++i)
  {
    int type;
    scanf ("%d:", &type);

    std::string line, query;
    std::getline (std::cin, line);
    query.assign (line.begin () + 1, line.end ());

    using PAIR_T = std::pair<Key, std::string>;
    Key k = { type, query };
    std::vector<PAIR_T> res (rec.lower_bound (k), rec.upper_bound (k));

    auto IDCmp = [](const PAIR_T &p1, const PAIR_T &p2) { return p1.second < p2.second; };
    std::sort (res.begin (), res.end (), IDCmp);

    printf ("%d: %s\n", type, query.c_str ());
    if (res.empty ())
      printf ("Not Found\n");
    else
    {
      for (auto i : res)
        std::cout << i.second << std::endl;
    }
  }

  return 0;
}