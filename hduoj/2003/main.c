#include <stdio.h>
#include <math.h>

int main()
{
  double t;
  while (scanf("%lf", &t) != EOF)
  {
    printf("%.2lf\n", fabs(t));
  }

  return 0;
}