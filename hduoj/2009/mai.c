#include <stdio.h>
#include <math.h>

int main()
{
  int i, n, m;
  double sum, t;
  while (scanf("%d%d", &n, &m) != EOF)
  {
    sum = n;
    t = n;
    for (i = 1; i < m; i++)
    {
      sum += sqrt(t);
      t = sqrt(t);
    }
    printf("%.2lf\n", sum);
  }
  return 0;
}