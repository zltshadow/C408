#include <stdio.h>

int main()
{
  int i, n;
  int sum;
  while (~scanf("%d", &n))
  {
    sum = 1;
    for (i = 1; i < n; i++)
    {
      sum = 2 * (1 + sum);
    }
    printf("%d\n", sum);
  }

  return 0;
}
