#include <stdio.h>

int main(int argc, char *argv[])
{
  int n, a[1001], i;
  while (scanf("%d", &n) != EOF)
  {
    int max = 0;
    // 找出最大的数
    for (i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      if (max < a[i])
      {
        max = a[i];
      }
    }
    int sum = max;
    i = 0;
    while (i != n)
    {
      for (i = 0; i < n; i++)
      {
        if (sum % a[i])
        {
          break;
        }
      }
      if (i == n)
      {
        break;
      }
      sum += max;
    }
    printf("%d\n", sum);
  }
  return 0;
}