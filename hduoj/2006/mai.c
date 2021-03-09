#include <stdio.h>

int main()
{
  int i, n, t, product;
  while (scanf("%d", &n) != EOF)
  {
    product = 1;
    for (i = 0; i < n; i++)
    {
      scanf("%d", &t);
      if (t % 2 != 0)
      {
        product *= t;
      }
    }
    printf("%d\n", product);
  }

  return 0;
}