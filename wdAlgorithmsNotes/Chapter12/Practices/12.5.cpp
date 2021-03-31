/*
* 题目名称：采药
* 题目来源：北京大学复试上机题
* 题目链接：http://dwz.win/Knc
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;
const int MAXM = 1000 + 10;

int dp[MAXM];
int value[MAXN];  //物品价值
int weight[MAXN]; //物品重量

int main()
{
    int n, m; //n件物品，m容量的背包
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &weight[i], &value[i]);
        }
        for (int i = 0; i <= m; ++i)
        {
            dp[i] = 0; //初始化
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = m; j >= weight[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}