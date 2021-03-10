#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int n;

  scanf("%d\n", &n);
  while (n--)
  {
    char c, flag = 1;
    c = getchar();
    if (!(isalpha(c) || c == '_'))
    {
      flag = 0;
    }
    while ((c = getchar()) != '\n')
    {
      if (!(isalnum(c) || c == '_'))
      {
        flag = 0;
      }
    }
    printf("%s\n", flag ? "yes" : "no");
  }

  return 0;
}