/*
* 题目名称：搬水果
* 题目来源：吉林大学复试上机题
* 题目链接：http://t.cn/AiCu5nsQ
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <queue>

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
        priority_queue<int, vector<int>, greater<int>> myPriorityQueue;
        while (n--)
        {
            int x;
            cin >> x;
            myPriorityQueue.push(x);
        }
        int answer = 0;
        while (1 < myPriorityQueue.size())
        {
            int a = myPriorityQueue.top();
            myPriorityQueue.pop();
            int b = myPriorityQueue.top();
            myPriorityQueue.pop();
            answer += a + b;
            myPriorityQueue.push(a + b);
        }
        cout << answer << endl;
    }
    return 0;
}