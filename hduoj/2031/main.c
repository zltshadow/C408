#include <stdio.h>
#include <math.h>
int main()
{
  int N, R;
  while (~scanf("%d %d", &N, &R))
  {
    int num, i = 0, c[10000];
    for (num = abs(N); num > 0; i++)
    {
      c[i] = num % R;
      num /= R;
    }
    i--;
    if (N < 0) //当输入的数是负数时，需要输出负号
      printf("-");
    for (; i >= 0; i--)
    {
      if (c[i] < 10)
        printf("%d", c[i]);
      else if (c[i] == 10)
        printf("A");
      else if (c[i] == 11)
        printf("B");
      else if (c[i] == 12)
        printf("C");
      else if (c[i] == 13)
        printf("D");
      else if (c[i] == 14)
        printf("E");
      else if (c[i] == 15)
        printf("F");
    }
    printf("\n");
  }
  return 0;
}