/*
* 题目名称：找X
* 题目来源：哈尔滨工业大学复试上机题
* 题目链接：http://t.cn/E9gHFnS
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 200;

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
        int x;
        cin >> x;
        int answer = -1;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == x)
            {
                answer = i;
                break;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
