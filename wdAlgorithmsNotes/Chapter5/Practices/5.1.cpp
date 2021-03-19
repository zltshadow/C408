/*
* 题目名称：堆栈的使用
* 题目来源：吉林大学复试上机题
* 题目链接：http://t.cn/AiKKM6F6
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        stack<int> Stack;
        for (int i = 0; i < n; ++i)
        {
            char c;
            cin >> c;
            if (c == 'A')
            {
                if (Stack.empty())
                {
                    cout << "E\n";
                }
                else
                {
                    cout << Stack.top() << endl;
                }
            }
            else if (c == 'O')
            {
                if (Stack.empty())
                {
                    continue;
                }
                else
                {
                    Stack.pop();
                }
            }
            else if (c == 'P')
            {
                int data;
                cin >> data;
                Stack.push(data);
            }
        }
        cout << endl;
    }
    return 0;
}
