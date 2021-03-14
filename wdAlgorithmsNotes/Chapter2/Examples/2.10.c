/*
* 题目名称：手机键盘
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9ulcIc
* 代码作者：zlt_shadow
*/
#include <stdio.h>
#include <string.h>
#define MAXN 100

int main()
{
    char str[MAXN];
    int keyTable[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

    while (gets(str))
    {
        int time = 0;
        for (int i = 0; i < strlen(str); ++i)
        {
            time += keyTable[str[i] - 'a'];                                                           //按键时间
            if (i != 0 && str[i] - str[i - 1] == keyTable[str[i] - 'a'] - keyTable[str[i - 1] - 'a']) // 同一按键字母的距离和 pos 之差应该相等
            {
                time += 2; //等待时间
            }
        }
        printf("%d\n", time);
    }
    return 0;
}
