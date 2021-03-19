/*
* 题目名称：String Matching
* 题目来源：上海交通大学复试上机题
* 题目链接：https://www.nowcoder.com/practice/00438b0bc9384ceeb65613346b42e88a?tpId=40&tPage=6&rp=6&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tab=answerKey
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXM = 1e6 + 10;

int nextTable[MAXM];

void GetNextTable(string pattern)
{ //创建next表
    int m = pattern.size();
    int j = 0;
    nextTable[j] = -1;
    int t = nextTable[j];
    while (j < m)
    {
        if (t == -1 || pattern[j] == pattern[t])
        {
            j++;
            t++;
            nextTable[j] = t;
        }
        else
        {
            t = nextTable[t];
        }
    }
    return;
}

int KMP(string text, string pattern)
{
    GetNextTable(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = 0;
    int j = 0;
    int number = 0; //记录匹配次数
    while (i < n)
    {
        if (j == -1 || text[i] == pattern[j])
        { //当前字符匹配成功
            i++;
            j++;
        }
        else
        {
            j = nextTable[j]; //当前字符匹配失败
        }
        if (j == m)
        { //模式串匹配成功
            number++;
            j = nextTable[j];
        }
    }
    return number;
}

int main()
{
    string text, pattern;
    while (cin >> text >> pattern)
    {
        cout << KMP(text, pattern) << endl;
    }
    return 0;
}