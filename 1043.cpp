#include <cstdio>
#include <vector>
#include <list>

using namespace std;

enum TreeType { WRONG, BST, MIRROR, ANY };

TreeType testAndPrint (vector<int>::iterator beg, vector<int>::iterator end, TreeType req, list<int> &post)
{
  if (beg == end || beg + 1 == end)
  {
    if (beg + 1 == end)
      post.push_back (*beg);

    if (req == ANY)
      req = BST;

    return req;
  }

  auto mid = end;
  TreeType res = ANY;

  if (*(beg + 1) < *beg)
  {
    auto ite = beg + 1;
    while (ite != end && *ite < *beg)
      ++ite;

    if (ite != end)
    {
      mid = ite++;
      while (ite != end && *(ite++) >= *beg)
        ;

      if (ite == end)
        res = BST;
      else
        return WRONG;
    }
  }
  else
  {
    auto ite = beg + 1;
    while (ite != end && *ite >= *beg)
      ++ite;

    if (ite != end)
    {
      mid = ite++;
      while (ite != end && *(ite++) < *beg)
        ;

      if (ite == end)
        res = MIRROR;
      else
        return WRONG;
    }
  }

  if (req == ANY && res == ANY)
  {
    TreeType ret = testAndPrint (beg + 1, end, ANY, post);
    post.push_back (*beg);

    return ret;
  }

  if (req == ANY)
    req = res;
  else if (res == ANY)
    res = req;

  if (req != res)
    return WRONG;

  TreeType retLeft = testAndPrint (beg + 1, mid, req, post);
  TreeType retRight = testAndPrint (mid, end, req, post);

  if (retLeft == WRONG || retRight == WRONG)
    return WRONG;
  post.push_back (*beg);

  return retLeft;
}

int main ()
{
  int num;
  scanf ("%d", &num);

  std::vector<int> arr (num);
  for (int i = 0; i < num; ++i)
    scanf ("%d", &arr[i]);

  list<int> post;
  auto ret = testAndPrint (arr.begin (), arr.end (), ANY, post);

  if (ret == WRONG)
    printf ("NO\n");
  else
  {
    printf ("YES\n");
    auto ite = post.begin ();
    while (1)
    {
      printf ("%d", *ite);
      if (++ite != post.end ())
        printf (" ");
      else
        break;
    }
    printf ("\n");
  }

  return 0;
}
