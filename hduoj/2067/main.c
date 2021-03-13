#include <stdio.h>

// 卡特兰数的递推及通项公式：
// h(n) = h(0)h(n-1) + h(1)h(n-2)+……+h(n-1)h(0) 用这个
// h(n) = h(n-1) × (4n-2)/(n+1)
// h(n) = C(n,2n) - C(n+1,2n) = C(n,2n)/(n+1)

int main()
{
  int n, i, k, j = 0;
  long long s[40] = {0};
  s[1] = 1;
  s[0] = 1;
  for (i = 2; i <= 35; i++)
  {
    for (k = 0; k < i; k++)
    {
      s[i] += s[k] * s[i - 1 - k];
    }
  }
  while (~scanf("%d", &n))
  {
    if (n == -1)
    {
      break;
    }
    printf("%d %d %I64d\n", ++j, n, s[n] * 2);
  }
}