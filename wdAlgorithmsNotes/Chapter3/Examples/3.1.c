/*
* 题目名称：排序
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/E9dLx5K
* 代码作者：zlt_shadow
*/

#include <stdio.h>

#define maxN 100

#include <stdio.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
    return;
}

// 下面示例的算法均是升序版
// 冒泡排序
void bubbleSort(int a[maxN], int len)
{
    int i, j;
    for (i = 0; i < len; i++)
        for (j = i; j < len; j++)
        {
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    return;
}

// 选择排序
void selectSort(int a[maxN], int len)
{
    int i, j, t;
    for (i = 0; i < len; i++)
    {
        t = i;
        for (j = i; j < len; j++)
        {
            if (a[t] > a[j])
            {
                t = j;
            }
        }
        if (t != i)
        {
            swap(&a[i], &a[t]);
        }
    }
    return;
}

// 插入排序
void insertSort(int a[maxN], int len)
{
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return;
}
int main(int argc, char *argv[])
{
    int i = 0, n, len;
    int arr[maxN];
    int arrSort[maxN];
    while (scanf("%d", &n) != EOF)
    {
        len = n;
        while (n--)
        {
            scanf("%d", &arr[i]);
            i++;
        }
        // bubbleSort(arr, len);
        selectSort(arr, len);
        for (i = 0; i < len; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}