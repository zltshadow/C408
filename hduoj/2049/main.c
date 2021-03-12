/*
思路：有n位新郎，但是又m位新郎会找错，那么有n-m位新郎会找对，而找对的n-m位新郎的找发就是在
n位新郎中随机找n-m位有多少种排列组合公式有n!/(m!*(n-m!))，而另外找错的新郎则按照错排公式来做
D(n)=(n-1)*(D(n-1)+D(n-2))
*/

#include <stdio.h>
long long p[25] = {1, 1, 0, 0};
long long q[25] = {1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
long long fac(int n)
{
  if (p[n] != 0)
  {
    return p[n];
  }
  return p[n] = fac(n - 1) * n;
}

long long recrusion(int n)
{
  if (q[n] > -1)
  {
    return q[n];
  }
  return q[n] = (n - 1) * (recrusion(n - 2) + recrusion(n - 1));
}

int main()
{
  int m;
  p[0] = 1;
  p[1] = 1;
  int a, b;
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
  {
    scanf("%d %d", &a, &b);
    printf("%lld\n", (fac(a) / (fac(b) * fac(a - b))) * recrusion(b));
  }
  return 0;
}