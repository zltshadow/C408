// #include <stdio.h>
// 这是暴力枚举法
// int main()
// {
//   int coin, count;
//   int i, j, k, l, m;
//   while (scanf("%d", &coin) != EOF)
//   {
//     if (coin < 0 || coin > 250)
//     {
//       printf("coin的取值范围为[0,250]之间的整数！\n");
//       continue;
//     }
//     if (coin == 0)
//     {
//       printf("1\n");
//       continue;
//     }
//     count = 0;
//     for (i = 0; i <= coin; i++)
//     {
//       for (j = 0; j * 5 <= coin - i; j++)
//       {
//         for (k = 0; k * 10 <= coin - i - j * 5; k++)
//         {
//           for (l = 0; l * 25 <= coin - i - j * 5 - k * 10; l++)
//           {
//             m = coin - i - j * 5 - k * 10 - l * 25;
//             if (i + j + k + l + m / 50 <= 100 && m % 50 == 0)
//             {
//               count++;
//             }
//           }
//         }
//       }
//     }
//     printf("%d\n", count);
//   }
//   return 0;
// }

#include <stdio.h>
#include <string.h>

// 使用母函数做，在本题中i是币值种类，有50,25,10,5,1五种币值 j表示当前的钱数，k表示取i时该面值的钱取的个数，p是控制题中说的总共的个数不超过100.res[20]代表硬币组合为20的组合数

#define MAX 251

int c1[MAX][101], c2[MAX][101];

int res[MAX];

int num[6] = {0, 1, 5, 10, 25, 50};

void init()
{
  int i, j, k, p;
  memset(c1, 0, sizeof(c1));
  memset(c2, 0, sizeof(c2));
  c1[0][0] = 1;
  for (i = 1; i <= 5; i++)
  {
    for (j = 0; j < MAX; j++)
    { //最大指数是250
      for (k = 0; k * num[i] + j < MAX; k++)
      {
        for (p = 0; p + k <= 100; p++)
        { //限制硬币总数不超过100
          c2[k * num[i] + j][p + k] += c1[j][p];
        }
      }
    }
    for (j = 0; j < MAX; j++)
    {
      for (k = 0; k < 101; k++)
      {
        c1[j][k] = c2[j][k];
        c2[j][k] = 0;
      }
    }
  }
  for (j = 1; j < MAX; j++)
  {
    for (k = 1; k < 101; k++)
    {
      res[j] += c1[j][k];
    }
  }
  res[0] = 1;
}

int main()
{
  int n;
  init();
  while (scanf("%d", &n) != EOF)
  {
    printf("%d\n", res[n]);
  }
  return 0;
}
