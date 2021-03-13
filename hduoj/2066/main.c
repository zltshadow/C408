#include <stdio.h>
#include <string.h>
#define maxn 1005
#define Max(A, B) ((A) > (B) ? (A) : (B))
#define Min(A, B) ((A) < (B) ? (A) : (B))

const int INF = 1000000;
int G[maxn][maxn];
int distance[maxn], intree[maxn];
int city[maxn], place[maxn];

void initialize()
{
  for (int i = 0; i <= 1000; ++i)
    for (int j = 0; j <= 1000; ++j)
      if (i == j)
        G[i][j] = G[j][i] = 0; //考虑如果想去的城市和小镇相连的城市刚好相连时答案为0
      else
        G[i][j] = INF;
  memset(city, 0, sizeof(city));
  memset(place, 0, sizeof(place));
}
void Dijkstra(int start, int n)
{
  int tempmin, node;

  memset(intree, 0, sizeof(intree));
  memset(distance, 0, sizeof(distance));
  for (int i = 1; i <= n; ++i)
    distance[i] = G[start][i];
  intree[start] = 1;
  for (int i = 1; i <= n - 1; ++i)
  {
    tempmin = INF;
    for (int j = 1; j <= n; ++j)
    {
      if (!intree[j] && tempmin > distance[j])
      {
        tempmin = distance[j];
        node = j;
      }
    }
    intree[node] = 1;
    for (int j = 1; j <= n; ++j)
      if (!intree[j])
        distance[j] = Min(distance[j], distance[node] + G[node][j]);
  }
}
int main()
{
  int T, S, D;
  int city1, city2, time, maxcity;

  while (scanf("%d%d%d", &T, &S, &D) != EOF)
  {
    initialize();
    maxcity = 0;
    while (T--)
    {
      scanf("%d%d%d", &city1, &city2, &time);
      if (Max(city1, city2) > maxcity)
        maxcity = Max(city1, city2); //求出最大城市编号
      if (G[city1][city2] > time)    //重边只取最小边
        G[city1][city2] = G[city2][city1] = time;
    }
    for (int i = 1; i <= S; ++i)
      scanf("%d", &city[i]);
    for (int i = 1; i <= D; ++i)
      scanf("%d", &place[i]);
    int mintime = INF;
    for (int i = 1; i <= S; ++i)
    {
      Dijkstra(city[i], maxcity);
      //Dijstra求出从start到任意一点的最短路径
      for (int j = 1; j <= D; ++j)
        if (distance[place[j]] < mintime)
          mintime = distance[place[j]];
    }
    printf("%d\n", mintime);
  }
  return 0;
}