/*
* 题目名称：最简真分数
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiCua2g8
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 600 + 10;

int arr[MAXN];

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a % b);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        int answer = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (GCD(arr[i], arr[j]) == 1)
                {
                    answer++;
                }
            }
        }
        cout << answer;
    }
    return 0;
}