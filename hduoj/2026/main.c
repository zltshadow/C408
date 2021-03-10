#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  char s[101];
  int i, len;
  while (gets(s) != NULL)
  {
    len = strlen(s);
    if (s[0] != ' ')
    {
      s[0] = s[0] - 32;
    }

    for (i = 1; i < len; i++)
    {
      if (s[i] != ' ' && s[i - 1] == ' ')
      {
        s[i] = s[i] - 32;
      }
    }
    puts(s);
  }
  return 0;
}