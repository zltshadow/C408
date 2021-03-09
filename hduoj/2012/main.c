#include <stdio.h>
#include <math.h>

int isPrime(int a)
{
  int i, flag = 1;
  for (i = 2; i <= sqrt((double)a); i++)
  {
    if (a % i == 0)
    {
      flag = 0;
      break;
    }
  }
  // 1:素数，0：非素数
  return flag;
}

int main()
{
  int x, y, i, n;
  double t;
  while ((scanf("%d%d", &x, &y)) != EOF)
  {
    if (x == 0 && y == 0)
    {
      break;
    }
    int flag = 1; // 0：[x,y]代表的表达式中不全是素数
    for (n = x; n <= y; n++)
    {
      t = n * n + n + 41;
      if (!isPrime(t))
      {
        flag = 0;
        break;
      }
    }
    if (flag)
    {
      printf("OK\n");
    }
    else
    {
      printf("Sorry\n");
    }
  }
  return 0;
}

// #include <stdio.h>
// #include <math.h>
// int isPrime(int a)
// {
//   int i;
//   //是从i=2开始，原来写成是1开始了，就wa了
//   for (i = 2; i <= sqrt((double)a); i++)
//   {
//     if (a % i == 0)
//     {
//       break;
//     }
//   }
//   if (i > sqrt((double)a))
//   {
//     return 1;
//   }
//   return 0;
// }
// int main()
// {
//   int x, y;
//   int result;
//   int i;
//   int count;
//   while (~scanf("%d%d", &x, &y))
//   {
//     if (x == 0 && y == 0)
//     {
//       break;
//     }
//     result = 0;
//     count = 0;
//     //for ( i = x+1; i < y; i++)
//     //按照题目的输入和输出，输出的是OK，如果是（0，1）范围内的话是没有整数的，何来对应的素数，所以题目应该理解为[0,1]->[x,y]
//     for (i = x; i <= y; i++)
//     {
//       result = i * i + i + 41;
//       if (isPrime(result))
//       {
//         count++; //记录使表达式的值为素数的数的个数
//       }
//     }
//     //if (count==(y-x-1))
//     if (count == (y - x + 1))
//     {
//       printf("OK\n");
//     }
//     else
//     {
//       printf("Sorry\n");
//     }
//   }
//   return 0;
// }