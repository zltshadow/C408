#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  char s[101];
  int n, i, len;
  scanf("%d\n", &n);
  while (n > 0)
  {
    while (gets(s) != NULL)
    {
      len = strlen(s);
      int sum[5] = {0};
      for (i = 0; i < len; i++)
      {
        switch (s[i])
        {
        case 'a':
          sum[0]++;
          break;
        case 'e':
          sum[1]++;
          break;
        case 'i':
          sum[2]++;
          break;
        case 'o':
          sum[3]++;
          break;
        case 'u':
          sum[4]++;
          break;
        default:
          break;
        }
      }
      printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", sum[0], sum[1], sum[2], sum[3], sum[4]);
      n--;
      if (n != 0)
      {
        printf("\n");
      }
    }
  }

  return 0;
}