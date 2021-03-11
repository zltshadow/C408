#include <stdio.h>
#include <string.h>
int main()
{
  int n;
  while (scanf("%d", &n) != EOF)
  {
    long int a[31][31] = {0};
    long int i = 1, j = 1, k = 0;
    for (; i <= n; ++i)
    {
      for (j = 1; j <= i; ++j)
      {
        if (j == 1)
          a[i][j] = 1;
        else if (j == i)
        {
          a[i][j] = 1;
          break;
        }
        else
          a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
      }
    }
    for (i = 1; i <= n; ++i)
    {
      for (j = 1; j <= i; ++j)
      {
        if (i != j)
        {
          printf("%d ", a[i][j]);
        }
        else
        {
          printf("%d\n", a[i][j]);
          break;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
