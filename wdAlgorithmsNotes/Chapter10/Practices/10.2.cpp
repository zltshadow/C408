/*
* 题目名称：查找第K小数
* 题目来源：北京邮电大学复试上机题
* 题目链接：http://t.cn/AiCu5hcK
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
        priority_queue<int, vector<int>, greater<int>> myPriorityQueue;
        while (n--)
        {
            int x;
            cin >> x;
            myPriorityQueue.push(x);
        }
        int k;
        cin >> k;
        int current = myPriorityQueue.top();
        myPriorityQueue.pop();
        for (int i = 1; i < k; ++i)
        {
            while (current == myPriorityQueue.top())
            {
                myPriorityQueue.pop();
            }
            current = myPriorityQueue.top();
            myPriorityQueue.pop();
        }
        cout << current << endl;
    }
    return 0;
}