#include <stdio.h>

int main(int argc, char *argv[])
{
  int N, AH, AM, AS, BH, BM, BS, ABH, ABM, ABS;
  while (scanf("%d", &N) != EOF)
  {
    for (int i = 0; i < N; i++)
    {
      scanf("%d %d %d %d %d %d", &AH, &AM, &AS, &BH, &BM, &BS);
      ABS = (AS + BS) % 60;
      ABM = (AM + BM + (AS + BS) / 60) % 60;
      ABH = AH + BH + (AM + BM + (AS + BS) / 60) / 60;
      printf("%d %d %d\n", ABH, ABM, ABS);
    }
  }
  return 0;
}