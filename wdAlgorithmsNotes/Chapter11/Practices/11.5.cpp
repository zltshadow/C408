/*
* 题目名称：Jungle Roads
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiW33P91
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Edge
{
    int from;   //边的起点
    int to;     //边的终点
    int length; //边的长度
    Edge() {}
    Edge(int f, int t, int l) : from(f), to(t), length(l) {}
    bool operator<(const Edge &e) const
    {
        return length < e.length;
    }
};

Edge edge[MAXN * MAXN]; //边集
int father[MAXN];       //父亲结点
int height[MAXN];       //结点高度

void Initial(int n)
{ //初始化
    for (int i = 0; i <= n; i++)
    {
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int x)
{ //查找根结点
    if (x != father[x])
    {
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y)
{ //合并集合
    x = Find(x);
    y = Find(y);
    if (x != y)
    {
        if (height[x] < height[y])
        {
            father[x] = y;
        }
        else if (height[y] < height[x])
        {
            father[y] = x;
        }
        else
        {
            father[y] = x;
            height[x]++;
        }
    }
    return;
}

int Kruskal(int n, int edgeNumber)
{
    Initial(n);
    sort(edge, edge + edgeNumber); //按权值排序
    int sum = 0;
    for (int i = 0; i < edgeNumber; ++i)
    {
        Edge current = edge[i];
        if (Find(current.from) != Find(current.to))
        {
            Union(current.from, current.to);
            sum += current.length;
        }
    }
    return sum;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            break;
        }
        int edgeNumber = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            char from;
            int number;
            cin >> from >> number;
            for (int j = 0; j < number; ++j)
            {
                char to;
                int length;
                cin >> to >> length;
                edge[edgeNumber++] = Edge(from - 'A', to - 'A', length);
            }
        }
        int answer = Kruskal(n, edgeNumber);
        printf("%d\n", answer);
    }
    return 0;
}