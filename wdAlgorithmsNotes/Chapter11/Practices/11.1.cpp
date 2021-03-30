/*
* 题目名称：找出直系亲属
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiOzTX5c
* 代码作者：zlt_shadow
*/

#include <cstdio>
#include <map>

#define N 26

using namespace std;

struct Node
{
    int p1;
    int p2;
} tree[N];

int preOrder(int from, int to, int depth)
{
    if (from == to)
        return depth;
    if (tree[from].p1 != -1)
    {
        int ret = preOrder(tree[from].p1, to, depth + 1);
        if (ret != -1)
            return ret;
    }
    if (tree[from].p2 != -1)
    {
        int ret = preOrder(tree[from].p2, to, depth + 1);
        if (ret != -1)
            return ret;
    }
    return -1;
}
int main()
{
    int n;
    int m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            tree[i].p1 = tree[i].p2 = -1;
        }
        while (n--)
        {
            char str[4];
            scanf("%s", str);
            if (str[1] != '-')
                tree[str[0] - 'A'].p1 = str[1] - 'A';
            if (str[2] != '-')
                tree[str[0] - 'A'].p2 = str[2] - 'A';
        }
        while (m--)
        {
            char str[3];
            scanf("%s", str);
            int from = str[0] - 'A';
            int to = str[1] - 'A';
            int ans1 = preOrder(from, to, 0);
            if (ans1 == 1)
                printf("child\n");
            else if (ans1 >= 2)
            {
                for (int i = ans1; i > 2; i--)
                    printf("great-");
                printf("grandchild\n");
            }
            else
            {
                int ans2 = preOrder(to, from, 0);
                if (ans2 == 1)
                    printf("parent\n");
                else if (ans2 >= 2)
                {
                    for (int i = ans2; i > 2; i--)
                        printf("great-");
                    printf("grandparent\n");
                }
                else
                    printf("-\n");
            }
        }
    }
    return 0;
}
