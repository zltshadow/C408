/*
* 题目名称：谁是你的潜在朋友
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiCux4f7
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 200 + 10;

int books[MAXN];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        map<int, int> myMap;
        for (int i = 0; i < n; ++i)
        {
            cin >> books[i];
            myMap[books[i]]++;
        }
        for (int i = 0; i < n; ++i)
        {
            if (myMap[books[i]] == 1)
            {
                cout << "BeiJu\n";
            }
            else
            {
                cout << myMap[books[i]] - 1 << endl;
            }
        }
    }
    return 0;
}