#include <stdio.h>
long long a[22] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
long long b[22] = {0};
long long fac(int n)
{
  if (b[n] > 0)
  {
    return b[n];
  }
  return b[n] = fac(n - 1) * n;
}
long long recrusion(int n)
{
  if (a[n] > -1)
    return a[n];
  return a[n] = (n - 1) * (recrusion(n - 2) + recrusion(n - 1));
}

int main()
{
  int n, m;
  int i;
  b[0] = 1;
  b[1] = 1;
  a[0] = 1;
  a[1] = 0;
  double x;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &m);
    x = (double)recrusion(m) / (double)fac(m);
    printf("%.2lf%%\n", x * 100);
  }
  return 0;
}
// （m大于7时概率不再变化）