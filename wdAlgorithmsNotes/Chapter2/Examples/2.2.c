/*
* 题目名称：反序数
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9WBrut
* 代码作者：zlt_shadow
*/
#include <stdio.h>

int Reverse(int number)
{ //求反序数
   int reverseNumber = 0;
   while (number != 0)
   {
      reverseNumber *= 10;
      reverseNumber += number % 10;
      number /= 10;
   }
   return reverseNumber;
}

int main(int argc, char *argv[])
{
   int i;
   for (i = 1000; i <= 1111; i++)
   {
      if (i * 9 == Reverse(i))
      {
         printf("%d", i);
      }
   }
   return 0;
}
