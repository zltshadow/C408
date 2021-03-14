/*
* 题目名称：abc
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9WMRTE
* 代码作者：zlt_shadow
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    for (a = 0; a <= 9; a++)
    {
        for (b = 0; b <= 9; b++)
        {
            for (c = 0; c <= 9; c++)
            {
                if (a * 100 + b * 10 + c * 1 + b * 100 + c * 10 + c * 1 == 532)
                {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
    return 0;
}
