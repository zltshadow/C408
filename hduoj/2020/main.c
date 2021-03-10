#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//本地测试都能使用，但使用杭电的OJ会报编译错误，可单独拿出来提交（冒泡本人测试已通过）

// 交换两个变量
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
//冒泡排序
void bubble_sort(int arr[], int len)
{
  int i, j, temp;
  for (i = 0; i < len - 1; i++)
    for (j = 0; j < len - 1 - i; j++)
      if (abs(arr[j]) > abs(arr[j + 1]))
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}
//选择排序
void selection_sort(int a[], int len)
{
  int i, j, temp;

  for (i = 0; i < len - 1; i++)
  {
    int min = i;                  // 记录最小值，第一个元素默认最小
    for (j = i + 1; j < len; j++) // 访问未排序的元素
    {
      if (abs(a[j]) < abs(a[min])) // 找到目前最小值
      {
        min = j; // 记录最小值
      }
    }
    if (min != i)
    {
      temp = a[min]; // 交换两个变量
      a[min] = a[i];
      a[i] = temp;
      /* swap(&a[min], &a[i]);  */ // 使用自定义函数交換
    }
  }
}
//插入排序
void insertion_sort(int arr[], int len)
{
  int i, j, temp;
  for (i = 1; i < len; i++)
  {
    temp = arr[i];
    for (j = i; j > 0 && abs(arr[j - 1]) > abs(temp); j--)
      arr[j] = arr[j - 1];
    arr[j] = temp;
  }
}
//希尔排序
void shell_sort(int arr[], int len)
{
  int gap, i, j;
  int temp;
  for (gap = len >> 1; gap > 0; gap = gap >> 1)
    for (i = gap; i < len; i++)
    {
      temp = arr[i];
      for (j = i - gap; j >= 0 && abs(arr[j]) > abs(temp); j -= gap)
        arr[j + gap] = arr[j];
      arr[j + gap] = temp;
    }
}
//归并排序
int min(int x, int y)
{
  return abs(x) < abs(y) ? x : y;
}
void merge_sort(int arr[], int len)
{
  int *a = arr;
  int *b = (int *)malloc(len * sizeof(int));
  int seg, start;
  for (seg = 1; seg < len; seg += seg)
  {
    for (start = 0; start < len; start += seg + seg)
    {
      int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
      int k = low;
      int start1 = low, end1 = mid;
      int start2 = mid, end2 = high;
      while (start1 < end1 && start2 < end2)
        b[k++] = abs(a[start1]) < abs(a[start2]) ? a[start1++] : a[start2++];
      while (start1 < end1)
        b[k++] = a[start1++];
      while (start2 < end2)
        b[k++] = a[start2++];
    }
    int *temp = a;
    a = b;
    b = temp;
  }
  if (a != arr)
  {
    int i;
    for (i = 0; i < len; i++)
      b[i] = a[i];
    b = a;
  }
  free(b);
}
//快速排序
typedef struct _Range
{
  int start, end;
} Range;
Range new_Range(int s, int e)
{
  Range r;
  r.start = s;
  r.end = e;
  return r;
}
void quick_sort(int arr[], int len)
{
  if (len <= 0)
    return; // 避免len等於負值時引發段錯誤（Segment Fault）
  // r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素
  Range r[len];
  int p = 0;
  r[p++] = new_Range(0, len - 1);
  while (p)
  {
    Range range = r[--p];
    if (range.start >= range.end)
      continue;
    int mid = arr[(range.start + range.end) / 2]; // 選取中間點為基準點
    int left = range.start, right = range.end;
    do
    {
      while (abs(arr[left]) < abs(mid))
        ++left; // 檢測基準點左側是否符合要求
      while (abs(arr[right]) > abs(mid))
        --right; //檢測基準點右側是否符合要求

      if (left <= right)
      {
        swap(&arr[left], &arr[right]);
        left++;
        right--; // 移動指針以繼續
      }
    } while (left <= right);

    if (range.start < right)
      r[p++] = new_Range(range.start, right);
    if (range.end > left)
      r[p++] = new_Range(left, range.end);
  }
}

int main()
{
  int n, i, j, num[101], flagArr[101];
  while (scanf("%d", &n) != EOF)
  {
    if (n == 0)
    {
      break;
    }
    for (i = 0; i < n; i++)
    {
      scanf("%d", &num[i]);
    }
    //调用上面任意排序算法
    bubble_sort(num, n);
    for (i = n - 1; i >= 0; i--)
    {
      if (i != n - 1)
      {
        printf(" ");
      }
      printf("%d", num[i]);
    }
    printf("\n");
  }
  return 0;
}