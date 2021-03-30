/*
* 题目名称：统计同成绩学生人数
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiCuM7nj
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <map>

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
        map<int, int> myMap;
        while (n--)
        {
            int score;
            cin >> score;
            myMap[score]++;
        }
        int query;
        cin >> query;
        cout << myMap[query] << endl;
    }
    return 0;
}