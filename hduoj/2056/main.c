#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
  return *(double *)a > *(double *)b ? 1 : -1;
}
int main()
{
  double s, l, h;
  double x[4], y[4];
  double x1, y1, x2, x3, x4, y2, y3, y4;
  while (~scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4))
  {
    x[0] = x1;
    x[1] = x2;
    x[2] = x3;
    x[3] = x4;
    y[0] = y1;
    y[1] = y2;
    y[2] = y3;
    y[3] = y4;
    qsort(x, 4, sizeof(x[0]), cmp);
    qsort(y, 4, sizeof(y[0]), cmp);
    l = fabs(x2 - x1) + fabs(x4 - x3) - (x[3] - x[0]);
    h = fabs(y2 - y1) + fabs(y4 - y3) - (y[3] - y[0]);
    s = l * h;
    if (l <= 0 || h <= 0) //推断不重叠的时候 为零由于题目有要求是精确到两位小数
      s = 0.00;
    printf("%.2lf\n", s);
  }
  return 0;
}