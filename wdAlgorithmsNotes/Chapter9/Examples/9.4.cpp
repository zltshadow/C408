/*
* 题目名称：Square
* 题目来源：POJ 2362
* 题目链接：http://poj.org/problem?id=2362
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 30;
int sticks[MAXN];
bool visit[MAXN];

bool DFS(int sum, int number, int position, int side, int m)
{
    if (number == 3)
    {
        return true;
    }
    int sample = 0; //剪枝(3)
    for (int i = position; i < m; ++i)
    {
        // 用过，大于平均边长
        if (visit[i] || sum + sticks[i] > side || sticks[i] == sample)
        {
            continue;
        }
        visit[i] = true;
        if (sum + sticks[i] == side)
        { //凑成一条边
            if (DFS(0, number + 1, 0, side, m))
            {
                return true;
            }
            else
            {
                sample = sticks[i]; //记录失败棍子长度
            }
        }
        else
        {
            if (DFS(sum + sticks[i], number, i + 1, side, m))
            {
                return true;
            }
            else
            {
                sample = sticks[i]; //记录失败棍子长度
            }
        }
        visit[i] = false;
    }
    return false;
}

bool Compare(int x, int y)
{
    return x > y;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;       //木棍数目
        int length = 0; //总长
        for (int i = 0; i < m; ++i)
        {
            cin >> sticks[i];
            length += sticks[i];
        }
        memset(visit, false, sizeof(visit));
        // 先排除总长不为4的倍数的以及木棍长大于平均边长的
        if (length % 4 != 0)
        { //剪枝(1)
            cout << "no\n";
            continue;
        }
        int side = length / 4;             //边长
        sort(sticks, sticks + m, Compare); //从大到小排序
        if (sticks[0] > side)
        { //剪枝(2)
            cout << "no\n";
            continue;
        }
        if (DFS(0, 0, 0, side, m))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}
