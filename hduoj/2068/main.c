#include <stdio.h>
// 错排计数。错位排列的公式有dn=n!(1-1/1!+1/2!-1/3!+...+(-1)^n*1/n!)
// 还有一个递推的形式 d[n]=(n-1)*(d[n-1]+d[n-2]) 。其中 d[0]=1  d[1]=0 d[2]=1;
// 这里采用第二种形式。对于N个数全排列，要求不是错排的个数大于或等于n的一半，
// 也就是错排的个数小于或等于n的一半，即错排的个数 从0到n/2 ，对每个错排的个数都有C（n,i）种选择，
// i为错排的个数，在n个数中挑i个来错排，c(n,i)* d[i] 即每种错排情况的个数，累加起来即可。
long long nn(int n, int m)
{
  int a = 1;
  for (int i = 1; i <= m; i++)
  {
    a = a * (n - i + 1); // 组合
    a /= i;
  }
  return a;
}
int main()
{
  long long a[30], sum;
  int n, i;
  a[1] = 0;
  a[2] = 1;
  for (i = 3; i <= 12; i++)
    a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
  while (scanf("%d", &n) != EOF)
  {
    if (n == 0)
      break;
    sum = 1;
    for (i = 1; i <= n / 2; i++)
      sum = sum + nn(n, i) * a[i];
    printf("%lld\n", sum);
  }
  return 0;
}
