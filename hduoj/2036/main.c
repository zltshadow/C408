#include <stdio.h>
int main()
{
  int n;
  int x[105], y[105];
  double sum;
  while (~scanf("%d", &n))
  {
    if (n == 0)
      break;
    sum = 0;
    scanf("%d%d", &x[1], &y[1]); //第一个点
    for (int i = 2; i <= n; i++)
    {
      scanf("%d%d", &x[i], &y[i]);
      sum += abs(x[i - 1] * y[i] - x[i] * y[i - 1]);
    }
    sum += abs(x[n] * y[1] - y[n] * x[1]); //首尾相连
    printf("%.1lf\n", sum / 2);
  }
  return 0;
}
