/*
* 题目名称：求root(N, k)
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AipAw4B1
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

int QuickPower(int x, int y, int k)
{
    int result = 1;
    x %= k;
    while (y != 0)
    {
        if (y % 2 == 1)
        {
            result *= x;
            result %= k;
        }
        x = (x * x) % k;
        y /= 2;
    }
    return result % k;
}
int main()
{
    int x, y, k;
    while (cin >> x >> y >> k)
    {
        int result = QuickPower(x, y, k - 1);
        if (x != 0 && result == 0)
        {
            result = k - 1;
        }
        cout << result << endl;
    }
    return 0;
}
