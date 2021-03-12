#include <stdio.h>

int main(int argc, char *argv[])
{
  int m, n, i, j;
  while (scanf("%d%d", &n, &m) != EOF)
  {
    for (i = 0; i <= m + 1; i++)
    {
      for (j = 0; j <= n + 1; j++)
      {
        if ((i == 0 && j == 0) || (i == 0 && j == n + 1) || (i == m + 1 && j == 0) || (i == m + 1 && j == n + 1))
        {
          printf("+");
        }
        else
        {
          if (i == 0 || i == m + 1)
          {
            printf("-");
          }
          else
          {
            if (j == 0 || j == n + 1)
            {
              printf("|");
            }
            else
            {
              printf(" ");
            }
          }
        }
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}