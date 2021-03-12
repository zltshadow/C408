/*
主要看最后一个是否为O，若为O，则倒数第二个不能为O，则为a[n-2]*1*2;
若不为O，则最后一个有两个选择则为a[n-1]*2
*/
#include <stdio.h>

long long a[40] = {0};

long long recrusion(int n)
{
  if (a[n] > 0)
  {
    return a[n];
  }
  return a[n] = recrusion(n - 2) * 2 + recrusion(n - 1) * 2;
}

int main()
{
  int n;
  a[1] = 3;
  a[2] = 8;
  while (~scanf("%d", &n))
  {
    recrusion(n);
    printf("%lld\n", a[n]);
  }
  return 0;
}