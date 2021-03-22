/*
* 题目名称：最大公约数
* 题目来源：哈尔滨工业大学复试上机题
* 题目链接：http://t.cn/AiCuWLTS
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

int GYS(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return GYS(b, a % b);
    }
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << GYS(a, b) << endl;
    }
    return 0;
}
