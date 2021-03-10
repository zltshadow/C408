#include <stdio.h>

int main()
{
  int n, num[101], i, t;
  while (scanf("%d", &n) != EOF)
  {
    if (n == 0)
    {
      break;
    }
    for (i = 0; i < n; i++)
    {
      scanf("%d", &num[i]);
    }
    int flag = 0;
    for (i = 1; i < n; i++)
    {
      if (num[flag] > num[i])
      {
        flag = i;
      }
    }
    if (flag)
    {
      t = num[0];
      num[0] = num[flag];
      num[flag] = t;
    }
    for (i = 0; i < n; i++)
    {
      if (i == 0)
      {
        printf("%d", num[i]);
      }
      else
      {
        printf(" %d", num[i]);
      }
    }
    printf("\n");
  }

  return 0;
}