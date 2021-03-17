/*
* 题目名称：排序
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/E9dLx5K
* 代码作者：zlt_shadow
*/
#include <iostream>
using namespace std;
const int MAXN = 100 + 10;

int arr[MAXN];

// 插入排序
void insertSort(int arr[MAXN], int len)
{
  int i, j, t;
  for (i = 1; i < len; i++)
  {
    t = arr[i];
    //找到小于哨兵的第一个数，移动哨兵之后的所有位置
    for (j = i - 1; j >= 0 && arr[j] > t; j--)
    {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = t;
  }
}

int main()
{
  int n, arr[MAXN], len;
  while (std::cin >> n)
  {
    len = 0;
    while (n--)
    {
      std::cin >> arr[len];
      len++;
    }
    insertSort(arr, len);
    for (int i = 0; i < len; i++)
    {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
