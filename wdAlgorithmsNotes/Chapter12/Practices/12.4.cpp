/*
* 题目名称：Coincidence
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/AiY03RO5
* 代码作者：zlt_shadow
*/
#include <stdio.h>
#include <string.h>
int Judge(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int main()
{
    char s1[100];
    char s2[100];
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);
    int n = strlen(s1 + 1);
    int m = strlen(s2 + 1);
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i] == s2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = Judge(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
