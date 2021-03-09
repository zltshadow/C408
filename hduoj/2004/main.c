#include <stdio.h>

int main()
{
  int score;
  while (scanf("%d", &score) != EOF)
  {
    if (90 <= score && score <= 100)
    {
      printf("A\n");
    }
    else if (80 <= score && score <= 89)
    {
      printf("B\n");
    }
    else if (70 <= score && score <= 79)
    {
      printf("C\n");
    }
    else if (60 <= score && score <= 69)
    {
      printf("D\n");
    }
    else if (0 <= score && score <= 59)
    {
      printf("E\n");
    }
    else
    {
      printf("Score is error!\n");
    }
  }

  return 0;
}