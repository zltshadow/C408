//2065 由4种字母组成，A和C只能出现偶数次。

// 构造指数级生成函数：(1+x/1!+x^2/2!+x^3/3!……)^2*(1+x^2/2!+x^4/4!+x^6/6!……)^2.

// 前面是B和D的情况，可以任意取，但是相同字母一样，所以要除去排列数。后者是A和C的情况，只能取偶数个情况。

// 根据泰勒展开，e^x在x0=0点的n阶泰勒多项式为 1+x/1!+x^2/2!+x^3/3!……

// 而后者也可以进行调整，需要把奇数项去掉，则e^(-x)的展开式为1-x/1!+X^2/2!-X^3/3!……

// 所以后者可以化简为(e^x+e^(-x))/2。则原式为(e^x)^2   *  ((e^x*e^(-x))/2)^2

// 整理得到e^4x+2*e^2x+1。

// 又由上面的泰勒展开

// e ^ 4x = 1 + (4x) / 1 !+(4x) ^ 2 / 2 !+(4x) ^ 3 / 3 !+... + (4x) ^ n / n !;

// e ^ 2x = 1 + (2x) / 1 !+(2x) ^ 2 / 2 !+(2x) ^ 3 / 3 !+... + (2x) ^ n / n !;

// 对于系数为n的系数为(4 ^ n + 2 * 2 ^ n) / 4 = 4 ^ (n - 1) + 2 ^ （n - 1）;

// 快速幂搞之。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//快速幂Fast Exponentiation
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % 100;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % 100;
    }
    return result;
}
int main()
{
  int T;
  int i;
  int temp;
  long long n;
  while (~scanf("%d", &T))
  {
    if (T == 0)
    {
      break;
    }
    for (i = 1; i <= T; i++)
    {
      scanf("%I64d", &n);
      temp = (fastPower(2, n - 1) + fastPower(4, n - 1)) % 100;
      printf("Case %d: %d\n", i, temp);
    }
    printf("\n");
  }
  return 0;
}