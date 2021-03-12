/*
当最后一个块可以和第一个块染相同颜色时，答案为：3*pow(2,n-1);
但是最后一块不能和第一块颜色相同，则减去和第一块颜色相同的染色种数即可,答案 3*pow(2,n-1)-divide(n-1)
*/

#include <stdio.h>
#include <math.h>
long long a[50] = {0};

long long divide(int n)
{
  if (n < 3 || a[n] > 0)
  {
    return a[n];
  }
  return a[n] = 3 * pow(2, n - 1) - divide(n - 1);
}

int main()
{
  int m;
  a[1] = 3;
  a[2] = 6;
  while (~scanf("%d", &m))
  {
    printf("%lld\n", divide(m));
  }
  return 0;
}