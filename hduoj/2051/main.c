#include <stdio.h>

int main(int argc, char *argv[])
{
  int n, a[1001], i;
  while (scanf("%d", &n) != EOF)
  {
    int merchant = n;
    i = 0;
    while (merchant != 0)
    {
      a[i] = merchant % 2;
      merchant /= 2;
      i++;
    }
    for (i = i - 1; i >= 0; i--)
    {
      printf("%d", a[i]);
    }
    printf("\n");
  }
  return 0;
}