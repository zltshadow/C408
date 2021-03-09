#include <stdio.h>
#include <math.h>

int main()
{
  int m, n;
  int x, y;
  while (scanf("%d%d", &m, &n) != EOF)
  {
    x = 0;
    y = 0;
    if (m > n)
    {
      int temp = m;
      m = n;
      n = temp;
    }
    for (int i = m; i <= n; i++)
    {
      if (i % 2 == 0)
      {
        x += pow(i, 2);
      }
      else
      {
        y += pow(i, 3);
      }
    }
    printf("%d %d\n", x, y);
  }
  return 0;
}
