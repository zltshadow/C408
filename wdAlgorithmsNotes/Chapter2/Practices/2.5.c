/*
* 题目名称：Hello World for U
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/E9jizni
* 代码作者：zlt_shadow
*/

#include <stdio.h>
#include <string.h>

#define MAXN 80

char matrix[MAXN][MAXN];

int main()
{
    char str[MAXN];
    while (gets(str))
    {
        int row = (strlen(str) + 2) / 3;
        int col = (strlen(str) + 2) - 2 * row;
        memset(matrix, 32, sizeof(matrix));
        int index = 0;
        for (int i = 0; i < row; ++i)
        {
            matrix[i][0] = str[index++];
        }
        for (int j = 1; j < col - 1; ++j)
        {
            matrix[row - 1][j] = str[index++];
        }
        for (int i = row - 1; i >= 0; --i)
        {
            matrix[i][col - 1] = str[index++];
        }
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
