#include <stdio.h>
#include <math.h>
int main()
{
  int a, b;
  int i, j, k;
  while (scanf("%d%d", &a, &b) != EOF && a && b)
  {
    for (j = (int)sqrt((double)(2 * b)); j >= 1; j--)
    {
      i = (2 * b / j + 1 - j) / 2;
      if (b == (2 * i + j - 1) * j / 2)
        printf("[%d,%d]\n", i, i + j - 1);
    }
    printf("\n");
  }
  return 0;
}