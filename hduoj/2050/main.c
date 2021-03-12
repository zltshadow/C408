#include <stdio.h>

int main()
{
  int m, n, p;
  while (scanf("%d", &p) != EOF)
  {
    while (p--)
    {
      scanf("%d", &n);
      m = 2 * n * n - n + 1;
      printf("%d\n", m);
    }
  }
  return 0;
}
