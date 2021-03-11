#include <stdio.h>

int main(int argc, char *argv[])
{
  int n, a, b, i, j, sum_a, sum_b;
  while (~scanf("%d", &n))
  {
    for (i = 0; i < n; i++)
    {
      scanf("%d%d", &a, &b);
      sum_a = 0;
      sum_b = 0;
      for (j = 1; j < a; j++)
      {
        if (a % j == 0)
        {
          sum_a += j;
        }
      }
      for (j = 1; j < b; j++)
      {
        if (b % j == 0)
        {
          sum_b += j;
        }
      }
      if (sum_a == b && sum_b == a)
      {
        printf("YES\n");
      }
      else
      {
        printf("NO\n");
      }
    }
  }
  return 0;
}