#include <cstdio>
#include <vector>
#include <algorithm>

int main ()
{
  int couponNum;
  scanf ("%d", &couponNum);

  std::vector<int> coupon (couponNum);
  for (int i = 0; i < couponNum; ++i)
    scanf ("%d", &coupon[i]);
  std::sort (coupon.begin (), coupon.end ());

  int productNum;
  scanf ("%d", &productNum);

  std::vector<int> product (productNum);
  for (int i = 0; i < productNum; ++i)
    scanf ("%d", &product[i]);
  std::sort (product.begin (), product.end ());

  int money = 0;
  for (int i = 0; i < couponNum && i < productNum; ++i)
  {
    if (coupon[i] < 0 && product[i] < 0)
      money += coupon[i] * product[i];
    else
      break;
  }

  for (int i = 0; i < couponNum && i < productNum; ++i)
  {
    int j = couponNum - 1- i, k = productNum - 1 - i;
    if (coupon[j] > 0 && product[k] > 0)
      money += coupon[j] * product[k];
    else
      break;
  }

  printf ("%d\n", money);

  return 0;
}