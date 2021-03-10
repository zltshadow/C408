/* HDU2019 数列有序! */

#include <stdio.h>

int main(void)
{
  int n, m, val, i;

  while (scanf("%d%d", &n, &m) != EOF)
  {
    if (n == 0 && m == 0)
      break;

    if (n == 0)
    {
      // n=0时，只需要输出m
      printf("%d\n", m);
    }
    else
    {
      // 读入n个数据，同时输出数据，并且在适当位置输出m
      int flag = 1;
      for (i = 0; i < n; i++)
      {
        scanf("%d", &val);

        if (flag && val >= m)
        {
          if (i == 0)
            printf("%d", m);
          else
            printf(" %d", m);
          flag = 0;
        }

        if (i > 0 || !flag)
          printf(" ");
        printf("%d", val);
      }
      if (flag)
        printf(" %d", m);
      printf("\n");
    }
  }

  return 0;
}
