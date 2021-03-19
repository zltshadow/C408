/*
* 题目名称：Zero-complexity Transposition
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/AiKa20bt
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<long long> sequence;

int main()
{
    int n;
    while (cin >> n)
    {
        while (n--)
        {
            long long number;
            cin >> number;
            sequence.push(number);
        }
        while (!sequence.empty())
        {
            cout << sequence.top() << " ";
            sequence.pop();
        }
        cout << endl;
    }
    return 0;
}
