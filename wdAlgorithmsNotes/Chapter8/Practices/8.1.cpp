/*
* 题目名称：杨辉三角形
* 题目来源：西北工业大学复试上机题
* 题目链接：http://t.cn/Ai0KcLRI
* 代码作者：zlt_shadow
*/

// 这题题目样例输出有问题，需省略第一行的1,否则无法通过

#include <iostream>
#include <cstdio>

using namespace std;

int Pascal(int row, int col)
{
    if (row == 1 || col == 1 || col == row)
    {
        return 1;
    }
    else
    {
        return Pascal(row - 1, col - 1) + Pascal(row - 1, col);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                if (i != j)
                {
                    cout << Pascal(i, j) << " ";
                }
                else if (i != 1)
                {
                    cout << Pascal(i, j) << endl;
                }
            }
        }
    }
    return 0;
}
