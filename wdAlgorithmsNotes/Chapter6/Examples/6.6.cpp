/*
* 题目名称：最小公倍数
* 题目来源：HDU 1108
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1108
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

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
    int a, b;
    while (cin >> a >> b)
    {
        cout << a * b / GCD(a, b) << endl;
    }
    return 0;
}
