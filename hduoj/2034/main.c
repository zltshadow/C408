#include <stdio.h>
int main()
{
  int n, m, i, j, num, flag, temp, a[101], b[101], c[101];
  while (~scanf("%d %d", &n, &m))
  {
    if (n == 0 && m == 0)
    {
      break;
    }
    for (i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
    }
    for (i = 0; i < m; i++)
    {
      scanf("%d", &b[i]);
    }
    num = 0;
    for (i = 0; i < n; i++)
    {
      flag = 0;
      for (j = 0; j < m; j++)
      {
        if (a[i] == b[j])
        {
          flag = 1;
        } //记的是i的不是j的
      }
      if (flag == 0)
      {
        c[num] = a[i];
        num++;
      }
    }
    if (num == 0)
    {
      printf("NULL");
    } //不要有回车否则会多一行

    for (i = 0; i < num; i++)
    { //选择排序（否则从小到大输出结果）题目给了要求
      for (j = i + 1; j < num + 1; j++)
      {
        if (c[i] > c[j])
        {
          temp = c[i];
          c[i] = c[j];
          c[j] = temp;
        }
      }
    }
    for (i = 0; i < num; i++)
    {
      printf("%d ", c[i]); //每个后必有空格，题目要求
    }
    printf("\n");
  }
}
