/*
* 题目名称：堕落的蚂蚁
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/E9dhoRA
* 代码作者：zlt_shadow
*/
//这题好难，剽窃的代码，膜拜大佬，大佬的思路如下：
//这题看起来像是模拟，其实可以不用那么复杂，挺有意思。
//首先要分析出一个重要结论： 两头的蚂蚁相碰的时候交换各自速度，其实就相当于两头蚂蚁还是各走各的路，没有碰头，速度没变，就好像穿过去了一样。
//实际上，从左边数第i个朝左的蚂蚁最终掉下去体现在左数第i个蚂蚁上，朝右的也一样。
#include <stdio.h>
#include <stdlib.h>

#define M 100

typedef struct mayi
{
    int p;
    int t;
} Mayi;

int cmp(const void *a, const void *b)
{
    return ((Mayi *)a)->p - ((Mayi *)b)->p;
}

int main(void)
{
    int left, position;
    int n, i, count;
    struct mayi m[M];

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d%d", &(m[i].p), &(m[i].t));
        qsort(m, n, sizeof(m[0]), cmp);

        left = 0;
        for (i = 0; i < n; i++)
        {
            if (m[i].t == 0)
                position = i;
            else if (m[i].t == -1)
                left++;
        }

        if (left == position)
            printf("Cannot fall!\n");
        else if (left > position)
        {
            count = 0;
            for (i = 0; i < n; i++)
            {
                if (m[i].t == -1)
                {
                    if (count == position)
                    {
                        printf("%d\n", m[i].p);
                        break;
                    }
                    count++;
                }
            }
        }
        else
        {
            count = 0;
            for (i = n - 1; i >= 0; i--)
            {
                if (m[i].t == 1)
                {
                    if (count == n - 1 - position)
                    {
                        printf("%d\n", 100 - m[i].p);
                        break;
                    }
                    count++;
                }
            }
        }
    }

    return 0;
}