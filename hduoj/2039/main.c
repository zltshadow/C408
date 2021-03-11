#include <stdio.h>
int main()
{
  float a, b, c;
  int m;
  scanf("%d", &m);
  while (m--)
  {
    while (~scanf("%f%f%f", &a, &b, &c))
    {
      if (a + b > c && a + c > b && b + c > a) //两边之和大于第三边
      {
        printf("YES");
      }
      else
      {
        printf("NO");
      }
      printf("\n");
    }
  }
  return 0;
}
