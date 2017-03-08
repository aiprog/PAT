#include <cstdio>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

struct Node
{
  int key;
  int next;
};

void formatIO (ostringstream &strout, int num)
{
  strout << setw (5) << setfill ('0') << num;
}

int main ()
{
  int head, nodeNum;
  scanf ("%d %d", &head, &nodeNum);

  vector<Node> lis (100000);
  for (int i = 0; i < nodeNum; ++i)
  {
    int addr, key, next;
    scanf ("%d %d %d", &addr, &key, &next);

    lis[addr] = Node { key, next };
  }

  vector<int> flag (10000);
  ostringstream resStrout, remStrout;
  bool resFirst = true, remFirst = true;

  for (; head != -1; head = lis[head].next)
  {
    auto &nd = lis[head];
    if (flag[abs (nd.key)])
    {
      if (remFirst)
        remFirst = false;
      else
      {
        formatIO (remStrout, head);
        remStrout << endl;
      }

      formatIO (remStrout, head);
      remStrout << " " << nd.key << " ";
    }
    else
    {
      flag[abs (nd.key)] = 1;
      if (resFirst)
        resFirst = false;
      else
      {
        formatIO (resStrout, head);
        resStrout << endl;
      }

      formatIO (resStrout, head);
      resStrout << " " << nd.key << " ";
    }
  }

  resStrout << -1 << endl;
  if (!remStrout.str ().empty ())
    remStrout << -1 << endl;
  printf ("%s%s", resStrout.str ().c_str (), remStrout.str ().c_str ());

  return 0;
}