/*
* 题目名称：完数VS盈数
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiKEyQWW
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> pefectNumber;   //完数
vector<int> abundantNumber; //盈数

int DivisorSum(int number)
{
    int sum = 0;
    for (int i = 1; i < number; ++i)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    for (int i = 2; i <= 60; ++i)
    {
        if (i == DivisorSum(i))
        {
            pefectNumber.push_back(i);
        }
        else if (i < DivisorSum(i))
        {
            abundantNumber.push_back(i);
        }
    }
    cout << "E:";
    for (int i = 0; i < pefectNumber.size(); ++i)
    {
        cout << " " << pefectNumber[i];
    }
    cout << endl;
    cout << "G:";
    for (int i = 0; i < abundantNumber.size(); ++i)
    {
        cout << " " << abundantNumber[i];
    }
    cout << endl;
    return 0;
}
