/*
* 题目名称：Case of Fugitive
* 题目来源：codeforces 555B
* 题目链接：http://codeforces.com/problemset/problem/555/B
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 2e5 + 10;

struct Island
{
    long long left;  //岛屿左端点
    long long right; //岛屿右端点
};

struct Bridge
{
    long long length; //桥的长度
    long long index;  //桥的编号
};

struct Interval
{
    long long minimum; //区间最小值
    long long maxmum;  //区间最大值
    long long index;   //区间编号
    bool operator<(Interval x) const
    {
        return maxmum > x.maxmum;
    }
};

Island island[MAXN];
Bridge bridge[MAXN];
Interval interval[MAXN];
long long answer[MAXN];

bool IntervalCompare(Interval x, Interval y)
{
    if (x.minimum == y.minimum)
    {
        return x.maxmum < y.maxmum;
    }
    else
    {
        return x.minimum < y.minimum;
    }
}

bool BridgeCompare(Bridge x, Bridge y)
{
    return x.length < y.length;
}

bool Solve(int n, int m)
{
    priority_queue<Interval> myQueue;
    int position = 0; //当前区间下标
    int number = 0;   //搭建桥的数目
    for (int i = 0; i < m; ++i)
    {
        while (!myQueue.empty() && myQueue.top().maxmum < bridge[i].length)
        {
            myQueue.pop(); //当前区间无法搭建
        }
        while (position < n && interval[position].minimum <= bridge[i].length && interval[position].maxmum >= bridge[i].length)
        {
            myQueue.push(interval[position]);
            position++;
        }
        if (!myQueue.empty())
        {
            Interval current = myQueue.top();
            myQueue.pop();
            answer[current.index] = bridge[i].index;
            number++;
        }
    }
    return number == n - 1; //判断桥数与区间数是否相等
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(island, 0, sizeof(island));
        memset(bridge, 0, sizeof(bridge));
        memset(interval, 0, sizeof(interval));
        memset(answer, 0, sizeof(answer));
        for (int i = 0; i < n; ++i)
        {
            cin >> island[i].left >> island[i].right;
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> bridge[i].length;
            bridge[i].index = i + 1;
        }
        for (int i = 0; i < n - 1; ++i)
        {
            interval[i].minimum = island[i + 1].left - island[i].right;
            interval[i].maxmum = island[i + 1].right - island[i].left;
            interval[i].index = i;
        }
        sort(interval, interval + n - 1, IntervalCompare);
        sort(bridge, bridge + m, BridgeCompare);
        if (Solve(n, m))
        {
            cout << "Yes\n";
            for (int i = 0; i < n - 1; ++i)
            {
                if (i == 0)
                {
                    cout << answer[i];
                }
                else
                {
                    cout << " " << answer[i];
                }
            }
            cout << "\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
