#include <stdio.h>
#include <string.h>
int main()
{
  char max, str[101];
  int len, i;
  while (~scanf("%s", str))
  {
    len = strlen(str);
    max = 'a';
    for (i = 0; i <= len - 1; i++)
    {
      if (str[i] > max)
      {
        max = str[i];
      }
    }
    for (i = 0; i <= len - 1; i++)
    {
      printf("%c", str[i]);
      if (str[i] == max)
      {
        printf("(max)");
      }
    }
    printf("\n");
  }
  return 0;
}
