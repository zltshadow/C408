/*
* 题目名称：成绩排序
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9d3ysv
* 代码作者：zlt_shadow
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 100;

struct Student
{
    int number;
    int score;
};

Student arr[maxN];

bool compare(Student x, Student y)
{
    if (x.score == y.score)
    {
        return x.number < y.number;
    }
    else
    {
        return x.score < y.score;
    }
}

int main()
{
    int i, j, n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i].number >> arr[i].score;
    }
    sort(arr, arr + n, compare);
    for (i = 0; i < n; i++)
    {
        cout << arr[i].number << " " << arr[i].score << endl;
    }

    return 0;
}