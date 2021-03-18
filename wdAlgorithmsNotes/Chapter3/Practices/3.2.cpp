/*
* 题目名称：整数奇偶排序
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/E9glPvp
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10];

bool Compare(int x, int y)
{
    if (x % 2 == 1 && y % 2 == 1)
    {
        return y < x;
    }
    else if (x % 2 == 0 && y % 2 == 0)
    {
        return x < y;
    }
    else
    {
        return x % 2 > y % 2;
    }
}

int main()
{
    while (cin >> arr[0])
    {
        for (int i = 1; i < 10; ++i)
        {
            cin >> arr[i];
        }
        sort(arr, arr + 10, Compare);
        for (int i = 0; i < 10; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
