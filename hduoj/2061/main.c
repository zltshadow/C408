#include <stdio.h>

int main()
{

  int n, k, flag;
  double a1, a2, cre, sco;

  scanf("%d", &n);

  while (n--)
  {
    a1 = 0.0;
    a2 = 0.0;
    flag = 0;
    scanf("%d", &k);
    while (k--)
    {
      scanf("%*s%lf%lf", &cre, &sco);
      if (sco < 60)
      {
        flag = 1;
      }
      a1 += cre * sco;
      a2 += cre;
    }
    if (flag == 1)
      printf("Sorry!\n");
    else
      printf("%.2lf\n", a1 / a2);
    if (n)
      printf("\n");
  }

  return 0;
}