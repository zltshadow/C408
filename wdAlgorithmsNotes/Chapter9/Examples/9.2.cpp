/*
* 题目名称：Find The Multiple
* 题目来源：POJ 1426
* 题目链接：http://poj.org/problem?id=1426
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

void BFS(int n)
{
    queue<long long> myQueue;
    myQueue.push(1); //压入初始状态
    while (!myQueue.empty())
    {
        long long current = myQueue.front();
        myQueue.pop();
        if (current % n == 0)
        { //查找成功
            cout << current << endl;
            return;
        }
        myQueue.push(current * 10);
        myQueue.push(current * 10 + 1);
    }
    return;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        BFS(n);
    }
    return 0;
}
