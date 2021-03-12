#include <stdio.h>
#include <math.h>
long long a[51] = {0};

long long divide(int n)
{
  if (n < 3 || a[n] > 0)
  {
    return a[n];
  }
  return a[n] = divide(n - 1) + divide(n - 2);
}

int main(int argc, char *argv[])
{
  int n;
  a[1] = 1;
  a[2] = 2;
  a[3] = 3;
  while (~scanf("%d", &n))
  {
    printf("%lld\n", divide(n));
  }
  return 0;
}