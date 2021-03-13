/*Subset sequence
Time Limit: 1000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 3183    Accepted Submission(s): 1652
Problem Description
Consider the aggregate An= { 1, 2, …, n }. For example, A1={1}, A3={1,2,3}. A subset sequence is defined as a array of a non-empty subset. 
Sort all the subset sequece of An in lexicography order. Your task is to find the m-th one.
Input
The input contains several test cases. Each test case consists of two numbers n and m ( 0< n<= 20, 0< m<= the total number of the subset 
sequence of An ).
 
Output
For each test case, you should output the m-th subset sequence of An in one line.
Sample Input
1 1
2 1
2 2
2 3
2 4
3 10
 
Sample Output
1
1
1 2
2
2 1
2 3 1
 
Author
LL
 
Source
校庆杯Warm Up 

拿测试数据3 10来做个示范，解释一下怎么求解。 
因为n=3，所以开始数组里1、2、3三个数。 
我们知道，n=2时，有4种排列，所以上面n=3可以分成三组，每组5个(加上空集)。 
因此第10个在第二组里。所以第一个是2，把2输出。原来的数组里删除2，变成1、3两个数。然后10 - (2 - 1) * 5 = 5，即它在第2组的第5个。 
减去首个空集合，5 - 1 = 4 ≠ 0，表示2后面还有数字。 
因为A1 = 1是，所以再第2组里又可以分成两组，每组2个(加上空集)。 
所以，4在第2组，剩下的数组中，第二个元素是3，所以输出3。再把数组里的3删除，剩下1一个数。 
然后4 - (2 - 1) * 2 = 2，既它是第2组的第2个。 
减去首个空集，2 - 1 = 1 ≠ 0，表示2后面还有数字。 
按上面的方法继续下去，直到n = 0 或 后面为空集为止。 
最后输出数组里的第1个元素，就得到2 3 1，就是解了。 
从上面的计算可以看出来，本题目的关键是先求的An中每一组的个数g(n) 
不难得出:g(n) = f(n) / n 
∵f(n) = n[f(n-1) + 1] 
∴g(n) = n[f(n-1) + 1] / n = f(n-1) + 1 
∵f(n-1) = (n-1) * g(n-1) 
∴g(n) = (n-1) * g(n-1) + 1
*/
#include <stdio.h>
int main()
{
  __int64 i, j, k, m, n, a[22], out, len[22];
  len[1] = 1;
  for (i = 2; i < 21; i++)
    len[i] = (i - 1) * len[i - 1] + 1; //对于每个n 以1~n为开头的序列数的组数是一样的 所以可以求出每个数的组数
  while (scanf("%I64d%I64d", &n, &m) != EOF)
  {
    for (i = 1; i < 21; i++) // 刚开始时每个i的对应位置都为i  随着i被取走，i位置后的值需要往前移
      a[i] = i;
    while (m)
    {
      k = (m - 1) / len[n] + 1; //求输出中的每个位置的数
      printf("%I64d", a[k]);
      for (j = k; j < 21; j++) //输出后更新数组中的值
        a[j] = a[j + 1];
      m %= len[n]; //每次还要更新输出中的下一个位置的位置
      if (m == 0)
        m = len[n];
      m--;
      n--; //输出一个数减一个
      if (m)
        printf(" ");
      else
        printf("\n");
    }
  }
  return 0;
}