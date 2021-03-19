/*
* 题目名称：后缀子串排序
* 题目来源：上海交通大学复试上机题
* 题目链接：https://www.nowcoder.com/practice/f89f96ea3145418b8e6c3eb75773f65a?tpId=40&tqId=21446&tPage=6&rp=6&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tab=answerKey
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string array[str.size()];
    for (int i = 0; i < str.size(); ++i)
    {
        array[i] = str.substr(i);
    }
    sort(array, array + str.size());
    for (int i = 0; i < str.size(); ++i)
    {
        cout << array[i] << endl;
    }
    return 0;
}