#include <stdio.h>

int main()
{
  int n, y;
  char c;
  scanf("%d\n", &n);
  while (n--)
  {
    scanf("%c", &c);
    scanf("%d\n", &y);
    if (c >= 'a' && c <= 'z')
      printf("%d\n", y - (int)(c - 'a' + 1));
    else if (c >= 'A' && c <= 'Z')
      printf("%d\n", y + (int)(c - 'A' + 1));
  }
  return 0;
}