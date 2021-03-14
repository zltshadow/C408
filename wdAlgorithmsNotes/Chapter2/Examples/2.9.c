/*
* 题目名称：剩下的树
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/E9ufYo5
* 代码作者：zlt_shadow
*/

#include <stdio.h>
#define MAXN 10000

int main()
{
    int length;
    int caseNumber;
    int treeNumber;
    int tree[MAXN];
    while (scanf("%d%d", &length, &caseNumber) != EOF)
    {
        for (int i = 0; i <= length; ++i)
        {
            tree[i] = 1;
        }
        int treeNumber = length + 1; //树的数量
        while (caseNumber--)
        {
            int left, right;
            scanf("%d%d", &left, &right);
            for (int i = left; i <= right; ++i)
            {
                if (tree[i])
                {
                    tree[i] = 0; //移除该树
                    treeNumber--;
                }
            }
        }
        printf("%d\n", treeNumber);
    }
    return 0;
}
