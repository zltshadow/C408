#include <stdio.h>

int main()
{
#define PI 3.1415927;
  double r, volume;
  while (scanf("%lf", &r) != EOF)
  {
    volume = r * r * r * 4 / 3 * PI;
    printf("%.3lf\n", volume);
  }

  return 0;
}