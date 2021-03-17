#include <stdio.h>

// 调用swap1打印结果：before   x = 100 y = 900
//                              after   x = 100 y = 900
// 分析：swap1函数进行数值交换，主函数并没有交换
// 调用swap2打印结果：before   x = 100 y = 900
//                              before   a = 0x7fff964a10e0 b = 0x7fff964a10e4
//                              after   a = 0x7fff964a10e0 b = 0x7fff964a10e4
//                              after   x = 900 y = 100
// 分析：swap2函数将地址中的数值进行交换，地址并没有交换
// 调用swap3打印结果：before   x = 100 y = 900
//                              before   a = 0x7ffc9979d920 *b = 0x7ffc9979d924
//                              after   a = 0x7ffc9979d924 b = 0x7ffc9979d920
//                              after   x = 100 y = 900
// 分析：swap3函数将地址进行交换，地址中的数值并没有交换

void swap1(int a, int b)
{
  int t;

  t = a;
  a = b;
  b = t;

  return;
}

void swap2(int *a, int *b)
{
  int t;
  printf("before   a = %p b = %p\n", a, b);

  t = *a;
  *a = *b;
  *b = t;

  printf("after   a = %p b = %p\n", a, b);
  return;
}

void swap3(int *a, int *b)
{
  int *t;
  printf("before   a = %p *b = %p\n", a, b);

  t = a;
  a = b;
  b = t;

  printf("after   a = %p b = %p\n", a, b);
  return;
}

int main(int argc, char const *argv[])
{
  int x = 100;
  int y = 900;

  printf("before   x = %d y = %d\n", x, y);
  // swap1(x, y);
  // swap2(&x, &y);
  swap3(&x, &y);
  printf("after   x = %d y = %d\n", x, y);
  return 0;
}