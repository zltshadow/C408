#include <stdio.h>
#include <string.h>
int main()
{
  int i, l, j, m;
  char a[51];
  scanf("%d", &m);
  getchar();
  while (m--)
  {
    gets(a);
    l = strlen(a);
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    for (i = 0; i < l; i++)
    {
      if (a[i] >= '0' && a[i] <= '9')
        a1 = 1;
      if (a[i] >= 'a' && a[i] <= 'z')
        a2 = 1;
      if (a[i] >= 'A' && a[i] <= 'Z')
        a3 = 1;
      if (a[i] == '~' || a[i] == '!' || a[i] == '@' || a[i] == '#' || a[i] == '$' || a[i] == '%' || a[i] == '^')
        a4 = 1;
    }
    j = a1 + a2 + a3 + a4;
    if ((j >= 3) && (l >= 8 && l <= 16))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}