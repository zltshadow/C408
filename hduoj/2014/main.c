#include <stdio.h>

int main()
{
  int n, i, t;
  while (scanf("%d", &n) != EOF)
  {
    double score;
    scanf("%d", &t);
    int min = t, max = t, sum = t;
    for (i = 1; i < n; i++)
    {
      scanf("%d", &t);
      sum += t;
      if (min > t)
      {
        min = t;
      }
      if (max < t)
      {
        max = t;
      }
    }
    score = (double)(sum - min - max) / (n - 2);
    printf("%.2lf\n", score);
  }

  return 0;
}