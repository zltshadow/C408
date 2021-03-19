/*
* 题目名称：猫狗收容所
* 题目来源：程序员面试金典
* 题目链接：无
* 代码作者：zlt_shadow
* 题目描述：
    有家动物收容所只收留猫和狗，但有特殊的收养规则，收养人有两种收养方式，
    第一种为直接收养所有动物中最早进入收容所的，
    第二种为选择收养的动物类型（猫或狗），并收养该种动物中最早进入收容所的。
    给定一个操作序列int[][2] ope(C++中为vector<vector<int>>)代表所有事件。
    若第一个元素为1，则代表有动物进入收容所，第二个元素为动物的编号，正数代表狗，负数代表猫；
    若第一个元素为2，则代表有人收养动物，
    若第二个元素为0，则采取第一种收养方式，若为1，则指定收养狗，若为-1则指定收养猫。
    请按顺序返回收养的序列。若出现不合法的操作，即没有可以符合领养要求的动物，则将这次领养操作忽略。
    测试样例：
    4
    1 1
    1 -1
    2 0
    2 -1
    返回：1 -1
*
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct animal
{
    int number; //动物编号
    int order;  //收容次序
    animal(int n, int o) : number(n), order(o) {}
};

queue<animal> cats;
queue<animal> dogs;

int main()
{
    int n;
    cin >> n;
    int order = 0;
    for (int i = 0; i < n; ++i)
    {
        int event;
        cin >> event;
        if (event == 1)
        {
            int number; //动物编号
            cin >> number;
            if (0 < number)
            {
                dogs.push(animal(number, order++));
            }
            else
            {
                cats.push(animal(number, order++));
            }
        }
        else
        {
            int type; //收养方式
            cin >> type;
            if (type == 0 && !dogs.empty() && !cats.empty())
            {
                if (dogs.front().order < cats.front().order)
                {
                    cout << dogs.front().number << " ";
                    dogs.pop();
                }
                else
                {
                    cout << cats.front().number << " ";
                    cats.pop();
                }
            }
            else if (type == 0 && dogs.empty() && !cats.empty())
            {
                cout << cats.front().number << " ";
                cats.pop();
            }
            else if (type == 0 && !dogs.empty() && cats.empty())
            {
                cout << dogs.front().number << " ";
                dogs.pop();
            }
            else if (type == 1 && !dogs.empty())
            {
                cout << dogs.front().number << " ";
                dogs.pop();
            }
            else if (type == -1 && !cats.empty())
            {
                cout << cats.front().number << " ";
                cats.pop();
            }
        }
    }
    printf("\n");
    return 0;
}
