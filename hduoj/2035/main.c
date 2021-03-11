#include <stdio.h>
int main()
{
  int a, b;
  while (~scanf("%d%d", &a, &b))
  {
    if (a == 0 && b == 0)
      break;
    int sum = 1;
    for (int i = 0; i < b; i++)
    {
      sum = sum * a % 1000; //不要先把数求出来再求余数，有可能会超过long long的范围，也很慢
    }
    printf("%d\n", sum);
  }
  return 0;
}
