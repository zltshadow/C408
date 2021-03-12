#include <stdio.h>

int main()
{
  /*
		L:赛道长度  
		N:供电站个数 
		C:电动车冲满电以后能行驶的距离  
		T:电动车每次充电所需要的时间
		VR:兔子跑步的速度
		VT1:乌龟开电动车的速度
		VT2:乌龟脚蹬电动车的速度
	*/
  int L, C, T, N, VR, VT1, VT2, i, j;
  //dis[i]表示第i个充电站离跑道起点的距离
  int dis[102];
  //dp[i]表示乌龟从起点到第i个充电站的最小时间
  double dp[102];
  //假设INF为本程序中的无穷大
  const double INF = 0xFFFFFFFF;
  int length;
  double time;
  while (scanf("%d", &L) != EOF)
  {
    scanf("%d%d%d", &N, &C, &T);
    scanf("%d%d%d", &VR, &VT1, &VT2);
    if (N <= 0 || N > 100)
    {
      printf("充电站的个数的取值范围为[1,100]之间的整数！\n");
      continue;
    }
    //输入各个充电站离道起点的距离
    for (i = 1; i <= N; i++)
    {
      scanf("%d", &dis[i]);
    }
    //将终点设为第N+1个充电站
    dis[N + 1] = L;
    //将起点设为第0个充电站
    dis[0] = 0;
    //起点到起点最小耗费时间为0
    dp[0] = 0;
    for (i = 1; i <= N + 1; i++)
    {
      //由于目前到第i个充电站的最小耗费时间未知，所以暂时设置为无穷大
      dp[i] = INF;
      for (j = 0; j < i; j++)
      {
        //从第j个加电站到第i个加电站的距离
        length = dis[i] - dis[j];
        //如果该距离大于电动车冲满电后能行驶的最大距离
        if (length > C)
        {
          //把电动车行驶的时间加上乌龟用脚踏的时间
          time = C * 1.0 / VT1 + (length - C) * 1.0 / VT2;
        }
        else
        {
          //直接加上这段距离除于电动车的速度所得的时间
          time = length * 1.0 / VT1;
        }
        time += dp[j];
        if (j > 0)
        {
          //j>0表示乌龟不是从起点出发，走完上述的路程后，电动车需要充电
          time += T;
        }
        //修改乌龟到第i个充电站的最短时间
        dp[i] = (dp[i] < time) ? dp[i] : time;
      }
    }
    //将兔子到达终点的时间与乌龟到达终点的时间进行比较
    if ((L * 1.0 / VR) > dp[N + 1])
    {
      printf("What a pity rabbit!\n");
    }
    else
    {
      printf("Good job,rabbit!\n");
    }
  }
  return 0;
}
