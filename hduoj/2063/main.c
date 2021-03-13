//匈牙利算法http://blog.csdn.net/dark_scope/article/details/8880547
/*思路：
*Rabbit只愿意和XHD或PQK做partner，
*Grass只愿意和linle或LL做partner，
*PrincessSnow愿意和水域浪子或伪酷儿做partner；
boss让找到partner的人去坐过山车,输出可以坐上过山车的最多组合数
*/
#include <stdio.h>
#include <string.h>
int line[510][510], boy[510], used[510];
int n, m;
int Find(int x)
{
  int i, j;
  for (i = 1; i <= m; i++) //遍历所有被选者
  {
    if (line[x][i] == 1 && used[i] == 0)
    {                                  //如果 x对i有好感且在这一个递归选取阶段没有被选取（哪怕是暂时选取，新的递归可能会换）
      used[i] = 1;                     //标记被选取
      if (boy[i] == 0 || Find(boy[i])) //如果被选者没有归属或他的归属着可以调换（他的归属者可以选择其它被选者）
      {
        boy[i] = x; //将归属定为 x
        return 1;
      }
    }
  }
  return 0;
}
int main()
{
  int i, j, k, x, y, sum;
  while (scanf("%d %d %d", &k, &n, &m), k != 0)
  {
    memset(line, 0, sizeof(line));
    memset(boy, 0, sizeof(boy));
    memset(used, 0, sizeof(used));
    for (i = 0; i < k; i++)
    {
      scanf("%d %d", &x, &y);
      line[x][y] = 1; //表示 x希望与 y有关系
    }
    sum = 0; //记录能撮合的情侣对数
    for (i = 1; i <= n; i++)
    {
      memset(used, 0, sizeof(used)); //每次都要清 0
      if (Find(i))
        sum++; //找到一对就记录
    }
    printf("%d\n", sum);
    //输出所有组合情况
    // for (i = 1; i <= n; i++)
    // {
    //   printf("girl:%d boy:%d\n", boy[i], i);
    // }
  }
  return 0;
}