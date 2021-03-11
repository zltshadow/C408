#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int n, i, start, end;
  char s[10000];
  while (scanf("%d\n", &n) != EOF)
  {
    for (i = 0; i < n; i++)
    {
      gets(s);
      end = strlen(s) - 1;
      int flag = 1;
      for (start = 0; start < end; start++, end--)
      {
        if (s[start] != s[end])
        {
          flag = 0;
        }
      }
      if (flag)
      {
        printf("yes\n");
      }
      else
      {
        printf("no\n");
      }
    }
  }
  return 0;
}