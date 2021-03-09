#include <stdio.h>
#include <math.h>

int main()
{
  int m, n, i, sum;
  while (scanf("%d%d", &m, &n) != EOF)
  {
    sum = 0;
    for (i = m; i <= n; i++)
    {
      int a, b, c; //百位a,十位b,个位c
      a = i / 100;
      b = i / 10 % 10;
      c = i % 10;
      if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
      {
        if (sum == 0)
        {
          printf("%d", i);
        }
        else
        {
          printf(" %d", i);
        }
        sum++;
      }
    }
    if (sum != 0)
    {
      printf("\n");
    }
    else
    {
      printf("no\n");
    }
  }
  return 0;
}