/*
* 题目名称：打印极值点下标
* 题目来源：北京大学复试上机题
* 题目链接：https://www.nowcoder.com/practice/7fd72f8ac7964ba3b8baa8735246e1f1?tpId=40&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tab=answerKey
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 80 + 10;

int arr[MAXN];

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        if (arr[0] != arr[1])
        {
            cout << 0 << " ";
        }
        for (int i = 1; i < n - 1; ++i)
        {
            if ((arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) || (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]))
            {
                cout << i << " ";
            }
        }
        if (arr[n - 2] != arr[n - 1])
        {
            cout << n - 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
