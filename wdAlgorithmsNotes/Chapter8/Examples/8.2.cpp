/*
* 题目名称：汉诺塔III
* 题目来源：HDU2064
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=2064
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

long long Function(int n)
{ //递归函数
    if (n == 1)
    { //递归出口
        return 2;
    }
    else
    { //递归调用
        return 3 * Function(n - 1) + 2;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << Function(n) << endl;
    }
    return 0;
}
