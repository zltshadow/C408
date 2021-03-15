/*
* 题目名称：路径打印
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/E9dvHs4
* 代码作者：zlt_shadow
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        char p[100][100]; // 存放测试集
        int f[100];       // 标记测试路径顺序
        for (int i = 0; i < n; i++)
        {                      // 循环输入测试路径
            scanf("%s", p[i]); // 输入一个测试路径数据
            f[i] = i;          // 标记各测试路径的原始顺序
        }

        // 对测试路径排序(根据每个路径根目录字符大小排序)
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int k = 0;
                while (p[f[i]][k] == p[f[j]][k])
                    k++;
                if (p[f[i]][k] > p[f[j]][k])
                {
                    int tmp = f[i];
                    f[i] = f[j];
                    f[j] = tmp;
                }
            }
        }

        // 打印测试路径
        for (int i = 0; i < n; i++)
        {
            int num = 0; // num表示当前路径输出的初始缩进
            for (int j = i - 1; j >= 0; j--)
            {                     // 判断根目录是否在已打印路径中出现过
                int k = 0, l = 0; // k用于遍历一条路径,l用于统计相同目录数
                while (p[f[j]][k] == p[f[i]][k] && p[f[j]][k + 1] == p[f[i]][k + 1])
                {
                    if (p[f[j]][k] != '\\')
                        l++;
                    k++;
                }
                if (num < 2 * l) // 更新初始缩进
                    num = 2 * l;
            }

            int j; // 起始输出目录下标
            if (num != 0)
            {            // 有重复的父目录
                j = num; // 起始输出下标=初始缩进
                if (p[i][j] == '\0')
                {                          // 除已出现目录外,无目录访问时
                    printf("%c", p[i][0]); // 需直接输出目录名,无缩进
                    num = 0;
                }
                for (int k = 0; k < num; k++) // 后续还有路径,则需先打印初始缩进
                    printf(" ");
            }
            else
                j = 0; // 无已出现目录,则从头开始打印

            while (p[f[i]][j] != '\0')
            {
                if (p[f[i]][j] != '\\')
                {
                    printf("%c", p[f[i]][j]);
                    num += 2; // 每输出一个目录,下个目录需增加两个右缩进
                }
                else
                {
                    if (p[f[i]][j + 1] != '\0')
                        printf("\n");
                    for (int k = 0; k < num; k++)
                        printf(" ");
                }
                j++;
            }
            printf("\n"); // 换行进行下一个目录输出
            if (i + 1 == n)
                printf("\n"); // 测试路径与测试路径之间需空一行
        }
    }
    return 0;
}