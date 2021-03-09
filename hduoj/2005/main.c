#include <stdio.h>

int main()
{
  int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year, month, date;
  int num = 0;
  while (scanf("%d/%d/%d", &year, &month, &date) != EOF)
  {
    num = 0;
    if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))
    {
      day[1] = 29;
    }
    else
    {
      day[1] = 28;
    }
    for (int i = 0; i < month - 1; i++)
    { //计算到当前日期的前一个月
      num += day[i];
    }
    num += date; //加上当月的天数
    printf("%d\n", num);
  }
  return 0;
}
