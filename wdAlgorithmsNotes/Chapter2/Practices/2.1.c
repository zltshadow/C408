/*
* 题目名称：与7无关的数 
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/E9lOOZQ
* 代码作者：zlt_shadow
*/
#include <stdio.h>

int Judge(int number)
{
    int flag = 0;
    if (number % 7 == 0)
    {
        flag = 1;
    }
    while (number != 0)
    {
        if (number % 10 == 7)
        {
            flag = 1;
        }
        number /= 10;
    }
    return flag;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (!Judge(i))
            {
                sum += i * i;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}