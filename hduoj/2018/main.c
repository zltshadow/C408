#include <stdio.h>

// 3种方案，1，递推，2.迭代，3.直接循环

// 递推式 f(n) = n n<=4，f(n) = f(n-1) + f(n-3) n>4
int cow(int n)
{
  if (n <= 4)
    return n;
  else
    return cow(n - 1) + cow(n - 3);
}

int main(void)
{
  int n, i;

  while (scanf("%d", &n) != EOF)
  {
    // 判定结束条件
    if (n == 0)
    {
      break;
    }

    // 1.递归
    // printf("%d\n", cow(n));
    // 2.迭代
    int f1, f2, f3, fn;
    if (n == 1)
      fn = 1;
    else if (n == 2)
      fn = 2;
    else if (n == 3)
      fn = 3;
    else
    {
      f1 = 1;
      f2 = 2;
      f3 = 3;
      for (i = 4; i <= n; i++)
      {
        fn = f1 + f3;
        f1 = f2;
        f2 = f3;
        f3 = fn;
      }
    }
    // printf("%d\n", fn);

    // 3.直接循环
    int temp, count, age[4]; //其中temp表示产仔的数量，age表示不同年龄母牛的数量，实际仅需要三个数即可，此处为了便于理解使得年龄与下标相对应
    age[1] = age[2] = 0;
    age[3] = 1;
    count = 1;
    for (int i = 2; i <= n; i++)
    {
      temp = age[3]; //本年的产仔的数量为上一年3岁母牛的数量
      count += temp;
      age[3] = age[3] + age[2];
      age[2] = age[1];
      age[1] = temp;
    }
    printf("%d\n", count);
  }

  return 0;
}