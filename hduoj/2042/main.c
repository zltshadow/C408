#include <stdio.h>

int main(int argc, char *argv[])
{
  int n, sum, a, i, j;
  while (scanf("%d", &n) != EOF)
  {
    for (i = 0; i < n; i++)
    {
      scanf("%d", &a);
      sum = 3;
      for (j = 0; j < a; j++)
      {
        sum = (sum - 1) * 2;
      }
      printf("%d\n", sum);
    }
  }
  return 0;
}