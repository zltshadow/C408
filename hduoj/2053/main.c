/*　　题目大意是指：有n个灯泡，按1-n编号，要操作n次，第i次操作是将标号是i的倍数的变成相反状态。
最终求得是n次操作后，编号为n的灯泡的状态，其实就是求n的约束有多少个，及灯泡n被操作了多少次*/
#include <stdio.h>
int main()
{
  int m;
  int i;
  int sum = 0;
  int sum2, flag;
  while (~scanf("%d", &m))
  {
    sum = 0;
    for (i = 1; i <= m; i++)
    {
      if (m % i == 0)
        sum++;
    }
    if (sum % 2 == 0)
    {
      printf("0\n");
    }
    else
    {
      printf("1\n");
    }
  }
  return 0;
}