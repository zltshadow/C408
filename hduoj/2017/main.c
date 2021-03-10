#include <stdio.h>
#include <string.h>

int main()
{
  int n, i, j;
  char s[1000];
  while (scanf("%d\n", &n) != EOF)
  {
    for (i = 0; i < n; i++)
    {
      gets(s);
      int sum = 0;
      for (j = 0; j < strlen(s); j++)
      {
        if (s[j] >= '0' && s[j] <= '9')
        {
          sum++;
        }
      }
      printf("%d\n", sum);
    }
  }

  return 0;
}