#include <stdio.h>
#include <math.h>

int main()
{
  int m, n, i, j;
  double sum;
  while (scanf("%d", &m) != EOF)
  {
    for (i = 0; i < m; i++)
    {
      scanf("%d", &n);
      sum = 0.0;
      for (j = 1; j <= n; j++)
      {
        if (j % 2 == 1)
        {
          sum += 1.0 / j;
        }
        else
        {
          sum -= 1.0 / j;
        }
      }
      printf("%.2lf\n", sum);
    }
  }
  return 0;
}