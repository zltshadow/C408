#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int i, n, j;
  unsigned char s[4096];
  while (scanf("%d\n", &n) != EOF)
  {
    for (i = 0; i < n; i++)
    {
      int count = 0;
      gets(s);
      for (j = 0; j < strlen(s); j++)
      {
        if (s[j] > 127)
        {
          count++;
        }
      }
      printf("%d\n", count / 2);
    }
  }
  return 0;
}