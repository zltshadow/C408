/*思路：假设将n层塔从A经B挪到C需要f[n]步。
那么具体的移动过程可以这样看：将上面n-1层从A经B挪到C需要f[n-1]步，
再将第n层从A挪到B，需要一步，
再将上n-1层从C经B挪到A，需要f[n-1]步，
再将第n层从B挪到C，需要一步，
再将上n-1层从A经B挪到C，需要f[n-1]步，总计3*f[n-1] + 2步，其中 f[1] = 2;*/
#include <stdio.h>
typedef long long ll;
#define N 36

int main()
{
  int n;
  ll dp[N];
  dp[0] = 0;
  dp[1] = 2;
  for (int i = 2; i < N; i++)
  {
    dp[i] = 3 * dp[i - 1] + 2;
  }
  while (~scanf("%d", &n))
  {
    printf("%lld\n", dp[n]);
  }
  return 0;
}