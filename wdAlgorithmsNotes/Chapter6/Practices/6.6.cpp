/*
* 题目名称：Prime Number
* 题目来源：上海交通大学复试上机题
* 题目链接：http://t.cn/AiCulrSh
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 10;

vector<int> prime;
bool isPrime[MAXN];

void Initial()
{
    fill(isPrime, isPrime + MAXN, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < MAXN; ++i)
    {
        if (!isPrime[i])
        {
            continue;
        }
        prime.push_back(i);
        if (i > MAXN / i)
        {
            continue;
        }
        for (int j = i * i; j < MAXN; j += i)
        {
            isPrime[j] = false;
        }
    }
    return;
}

int main()
{
    Initial();
    int k;
    while (cin >> k)
    {
        cout << prime[k - 1] << endl;
    }
    return 0;
}