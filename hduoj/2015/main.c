#include <stdio.h>

int main()
{
  int n, m, i, j;
  while (scanf("%d%d", &n, &m) != EOF)
  {
    for (i = 0; i < n; i += m)
    {
      int sum = 0, count = 0;
      for (j = i; (j < i + m) && (j < n); j++)
      {
        sum += (j + 1) * 2;
        count++;
      }
      if (i == 0)
      {
        printf("%d", sum / count);
      }
      else
      {
        printf(" %d", sum / count);
      }
    }
    printf("\n");
  }

  return 0;
}