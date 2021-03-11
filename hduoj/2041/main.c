#include <stdio.h>
int main(void)
{
  int a[40];
  int n, i, k;
  //初始化数据
  a[0] = 0;
  a[1] = 1;
  a[2] = 2;

  for (i = 3; i < 40; i++)
  { //预先存储所有可能的结果
    a[i] = a[i - 1] + a[i - 2];
  }

  while (scanf("%d", &n) != EOF)
  {
    for (i = 0; i < n; i++)
    {
      scanf("%d", &k);
      printf("%d\n", a[k - 1]);
    }
  }
  return 0;
}