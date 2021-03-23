/*
* 题目名称：Fibonacci
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/Ai0K3tU5
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

int Fibonacci(int n)
{
    if (n == 1 || n == 0)
    { //递归出口
        return n;
    }
    else
    { //递归调用
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << Fibonacci(n) << endl;
    }
    return 0;
}
