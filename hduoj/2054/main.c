#include <stdio.h>
#include <string.h>
// 这道题题意简单，判断A和B是否相等，但是A和B不能直接比较，前补0要去掉，小数点后末尾0也要去掉。
#define N 100020
char a[N], b[N];
int main()
{
  int i, j, l1, l2, l3, l4, len1, len2;
  while (scanf("%s%s", a, b) != EOF)
  {
    len1 = strlen(a);
    len2 = strlen(b);
    len1--;
    len2--;
    for (i = 0; i <= len1; i++)
      if (a[i] != '0')
        break;
    l1 = i;
    l2 = len1;
    for (j = len1; j >= 0; j--)
    {
      if (a[j] == '.')
      {
        for (i = len1; i >= l1; i--)
        {
          if (a[i] == '.')
          {
            i--;
            break;
          }
          if (a[i] != '0')
            break;
        }
        l2 = i;
        break;
      }
    }

    for (i = 0; i <= len2; i++)
    {
      if (b[i] != '0')
        break;
    }

    l3 = i;
    l4 = len2;
    for (j = len2; j >= 0; j--)
    {
      if (b[j] == '.')
      {
        for (i = len2; i >= l3; i--)
        {
          if (b[i] == '.')
          {
            i--;
            break;
          }
          if (b[i] != '0')
            break;
        }
        l4 = i;
        break;
      }
    }

    int temp = 1;
    i = l1;
    j = l3;

    for (; i <= l2 && j <= l4;)
    {
      if (a[i] != b[j])
      {
        temp = 0;
        break;
      }
      i++;
      j++;
    }
    if (i != l2 + 1 || j != l4 + 1)
      temp = 0;
    if (temp == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}