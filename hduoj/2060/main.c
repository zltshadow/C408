#include <stdio.h>

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  while (n--)
  {
    int i, j, a, b, c, sum = 0;
    scanf("%d%d%d", &a, &b, &c);
    if (a > 6)
      puts(b + (a - 6) * (1 + 7) + 27 >= c ? "Yes" : "No");
    else
    {
      for (i = 7, j = 0; j < a; j++, i--)
        sum += i;
      puts(b + sum >= c ? "Yes" : "No");
    }
  }
  return 0;
}