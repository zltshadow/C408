/*
* 题目名称：输出梯形
* 题目来源：清华大学复试上机题
* 题目链接：无
* 代码作者：zlt_shadow
*/

// 题目描述：
// 输入一个高度h，输出一个高为h，上底边为h的梯形。

// 输入：
// 一个整数h(1<=h<=1000)。

// 输出：
// h所对应的梯形。

// 样例输入：
// 4
// 样例输出：
//       ****
//     ******
//   ********
// **********
// 提示：
// 梯形每行都是右对齐的，sample中是界面显示问题

#include <stdio.h>

int main(int argc, char *argv[])
{
    int h;
    while (scanf("%d", &h) != EOF)
    {
        int row = h;               //行数
        int col = h + (h - 1) * 2; //列数
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (j < col - (h + 2 * i))
                { //输出空格
                    printf(" ");
                }
                else
                { //输出星号
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
