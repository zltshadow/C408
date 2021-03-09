#include <stdio.h>
#include <math.h> //为了使用开根函数,求指函数

int main()
{
  double x1, y1, x2, y2; //输入数据会是实数
  double distance = 0;
  while (scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2) != EOF)
  {
    distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    printf("%.2lf\n", distance); //保留两位小数
  }
  return 0;
}
