#include <stdio.h>
int a[100], b[100];
int main()
{
  int n, i, j;
  while (~scanf("%d", &n) && n != 0)
  {
    for (i = 0; i < n; i++)
      scanf("%d %d", &a[i], &b[i]); //a[]开始时间，b[]结束时间
    int count = 1;
    int t;
    for (i = 0; i < n - 1; i++) //选择排序、按照结束时间排序
      for (j = i + 1; j < n; j++)
        if (b[i] > b[j])
        {
          t = b[i];
          b[i] = b[j];
          b[j] = t;
          t = a[i];
          a[i] = a[j];
          a[j] = t;
        }

    int y = b[0]; //第一个结束时间
    for (int i = 1; i < n; i++)
    {
      if (y <= a[i])
      {           //找到比前一个结束时间还晚的开始时间
        y = b[i]; //y只是个无情的结束时间，与i无关
        count++;
      }
    }
    printf("%d\n", count);
  }
  return 0;
}
