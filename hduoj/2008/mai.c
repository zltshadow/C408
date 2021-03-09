#include <stdio.h>

int main()
{
  int i, n;
  double t;
  int a, b, c;
  while (scanf("%d", &n) != EOF)
  {
    a = 0;
    b = 0;
    c = 0;
    for (i = 0; i < n; i++)
    {
      scanf("%lf", &t);
      if (t < 0)
      {
        a++;
      }
      else if (t == 0)
      {
        b++;
      }
      else if (t > 0)
      {
        c++;
      }
    }
    if (n != 0)
    {
      printf("%d %d %d\n", a, b, c);
    }
  }
  return 0;
}