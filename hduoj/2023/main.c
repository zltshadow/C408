#include <stdio.h>

int main()
{
  double stu_score[51][6], course_score[6], t;
  int sum, x, n, m;
  while (scanf("%d%d", &n, &m) != EOF)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        //输入数据
        scanf("%lf", &stu_score[i][j]);
      }
    }
    //学生平均成绩
    for (int i = 0; i < n; i++, t = 0)
    {
      for (int j = 0; j < m; j++)
      {
        t += stu_score[i][j];
      }
      if (i != 0)
      {
        printf(" ");
      }
      printf("%.2lf", t / m);
    }
    printf("\n");
    //课程平均成绩
    for (int i = 0; i < m; i++, t = 0)
    {
      for (int j = 0; j < n; j++)
      {
        t += stu_score[j][i];
      }
      if (i != 0)
      {
        printf(" ");
      }
      course_score[i] = t / n;
      printf("%.2lf", course_score[i]);
    }
    printf("\n");
    //各门成绩大于等于平均成绩的学生数量
    sum = 0;
    x = 0;
    for (int i = 0; i < n; i++, x = 0)
    {
      for (int j = 0; j < m; j++)
      {
        if (stu_score[i][j] >= course_score[j])
        {
          x++;
        }
      }
      if (x == m)
      {
        sum++;
      }
    }
    printf("%d\n\n", sum);
  }
  return 0;
}
