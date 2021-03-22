/*
* 题目名称：计算两个矩阵的乘积
* 题目来源：哈尔滨工业大学复试上机题
* 题目链接：http://t.cn/Aip450PJ
* 代码作者：zlt_shadow
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100;

struct Matrix
{
    int matrix[MAXN][MAXN];
    int row, col;                            //行与列
    Matrix(int r, int c) : row(r), col(c) {} //构造函数
};

Matrix Multiply(Matrix x, Matrix y)
{ //矩阵乘法
    Matrix answer(x.row, y.col);
    for (int i = 0; i < answer.row; ++i)
    {
        for (int j = 0; j < answer.col; ++j)
        {
            answer.matrix[i][j] = 0;
            for (int k = 0; k < x.col; ++k)
            {
                answer.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
            }
        }
    }
    return answer;
}

void InputMatrix(Matrix &x)
{ //矩阵输入
    for (int i = 0; i < x.row; ++i)
    {
        for (int j = 0; j < x.col; ++j)
        {
            cin >> x.matrix[i][j];
        }
    }
}

void OutputMatrix(Matrix x)
{ //矩阵输出
    for (int i = 0; i < x.row; ++i)
    {
        for (int j = 0; j < x.col; ++j)
        {
            cout << x.matrix[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    Matrix x(2, 3);
    Matrix y(3, 2);
    InputMatrix(x);
    InputMatrix(y);
    Matrix answer = Multiply(x, y);
    OutputMatrix(answer);
    return 0;
}
