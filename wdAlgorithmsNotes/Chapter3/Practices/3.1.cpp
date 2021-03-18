/*
* 题目名称：特殊排序
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/E9gio39
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cout << arr[n - 1] << endl;
        for (int i = 0; i < n - 1; ++i)
        {
            cout << arr[i] << " ";
        }
        if (n == 1)
        {
            cout << "-1";
        }
        cout << "\n";
    }
    return 0;
}
