#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// 例子：为二维数组分配3行5列
//  int **a = (int **)malloc(3 * sizeof(int *));
//  // 为每行分配5列
//  for(int i = 0; i < 3; i++)
//  {
//       a[i] = (int *)malloc(5 * sizeof(int));
//  }

//动态申请整数row行col列二维数组
int **malloc_Int_Array2D(int row, int col)
{
  int size = sizeof(int);
  int point_size = sizeof(int *);
  //先申请内存，其中point_size * row表示存放row个行指针
  int **arr = (int **)malloc(row * point_size);
  for (int i = 0; i < row; i++)
  {
    arr[i] = (int *)malloc(col * sizeof(int));
  }
  return (int **)arr;
}
//释放二维数组
void free_Aarray2D(void **arr)
{
  if (arr != NULL)
    free(arr);
}

int main(int argc, char *argv[])
{
  int m, n, i, j;
  int **mm;
  while ((scanf("%d%d", &m, &n)) != EOF)
  {
    mm = malloc_Int_Array2D(m, n);
    for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
      {
        scanf("%d", &mm[i][j]);
      }
    }
    int max_abs_i = 0, max_abs_j = 0;
    for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (abs(mm[max_abs_i][max_abs_j]) < abs(mm[i][j]))
        {
          max_abs_i = i;
          max_abs_j = j;
        }
      }
    }
    printf("%d %d %d\n", max_abs_i + 1, max_abs_j + 1, mm[max_abs_i][max_abs_j]);
  }
  free_Aarray2D(mm);
  return 0;
}