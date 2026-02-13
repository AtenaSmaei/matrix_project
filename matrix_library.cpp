#include "matrix_library.h"
#include <iostream>
#include <cmath>

using namespace std;

matrix addmatrices(matrix matrix1, matrix matrix2)
{
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        cout << "error : rows and columns of two matrices are not equel" << endl;
        return {};
    }
    int r = matrix1.size();
    int c = matrix1[0].size();
    matrix result(r, vec(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

matrix subtractmatrices(matrix matrix1, matrix matrix2)
{
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        cout << "error : rows and columns of two matrices are not equel" << endl;
        return {};
    }
    int r = matrix1.size();
    int c = matrix1[0].size();
    matrix result(r, vec(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

matrix scalarmultiply(matrix matrix1, double k)
{
    int r = matrix1.size();
    int c = matrix1[0].size();
    matrix result(r, vec(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = matrix1[i][j] * k;
        }
    }
    return result;
}

matrix multiplymatrices(matrix matrix1, matrix matrix2)
{
    int r1 = matrix1.size();
    int c1 = matrix1[0].size();
    int r2 = matrix2.size();
    int c2 = matrix2[0].size();

    if (c1 != r2)
    {
        cout << "error : columns of first matrix must equel rows of second matrix" << endl;
        return {};
    }
    matrix result(r1, vec(c2, 0.0));
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < c1; k++)
            {

                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

matrix transposematrix(matrix matrix1)
{
    int r = matrix1.size();
    int c = matrix1[0].size();
    matrix result(c, vec(r));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[j][i] = matrix1[i][j];
        }
    }
    return result;
}

vec addvectors(vec a, vec b)
{
    if (a.size() != b.size())   
    {
        cout << "error : vector must have same size" << endl;
        return {};
    }
    int n = a.size();
    vec result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = a[i] + b[i];
    }
    return result;
}

vec subtract(vec a, vec b)
{
    if (a.size() != b.size())
    {
        cout << "error : vector must have same size" << endl;
        return {};
    }
    int n = a.size();
    vec result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = a[i] - b[i];
    }
    return result;
}

vec scalarmultiply(vec a, double k)
{
    int n = a.size();
    vec result(n);

    for (int i = 0; i < n; i++)
    {
        result[i] = a[i] * k;
    }
    return result;
}

double dotproduct(vec a, vec b)
{
    if (a.size() != b.size())
    {
        cout << "erroe : vector must have the same size" << endl;
        return 0;
    }
    int n = a.size();
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }
    return sum;
}

vec crossproduct(vec a, vec b)
{
    if (a.size() != 3 || b.size() != 3)
    {
        cout << "erroe : vector must be 3D" << endl;
        return {};
    }
    vec result(3);
    result[0] = (a[1] * b[2]) - (a[2] * b[1]);
    result[1] = (a[2] * b[0]) - (a[0] * b[2]);
    result[2] = (a[0] * b[1]) - (a[1] * b[0]);

    return result;
}

double magnitude(vec a)
{
    int n = a.size();
    double sum_of_squares = 0;
    for (int i = 0; i < n; i++)
    {
        sum_of_squares += a[i] * a[i];
    }
    return sqrt(sum_of_squares);
}

vec normalize(vec a)
{
    double mag = magnitude(a);
    if (mag == 0)
    {
        cout << "error cannot normalize" << endl;
        return a;
    }
    int n = a.size();
    vec result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = a[i] / mag;
    }
    return result;
}

matrix get_minor(matrix m, int col)
{
    int n = m.size();
    matrix minor_mat;
    for (int i = 1; i < n; i++)
    {
        vec row;
        for (int j = 0; j < n; j++)
        {
            if (j != col)
                row.push_back(m[i][j]);
        }
        minor_mat.push_back(row);
    }
    return minor_mat;
}

double determinant(matrix matrix1)
{
    int n = matrix1.size();

    if (n != matrix1[0].size())
    {
        cout << "error : only squere matrix" << endl;
        return 0;
    }
    if (n == 1)
        return matrix1[0][0];
    if (n == 2)
    {
        return (matrix1[0][0] * matrix1[1][1]) - (matrix1[0][1] * matrix1[1][0]);
    }
    double det = 0;
    int sign = 1;
    for (int j = 0; j < n; j++)
    {
        det += sign * matrix1[0][j] * determinant(get_minor(matrix1, j));
        sign = -1 * sign;
    }
    return det;
}

matrix cofactor(matrix m)
{
    int n = m.size();
    matrix res(n, vec(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            matrix sub;
            for (int r = 0; r < n; r++)
            {
                if (r == i)
                    continue;
                vec row;
                for (int c = 0; c < n; c++)
                {
                    if (c == j)
                        continue;
                    row.push_back(m[r][c]);
                }
                sub.push_back(row);
            }
            double sign = ((i + j) % 2 == 0) ? 1 : -1;
            res[i][j] = sign * determinant(sub);
        }
    }
    return res;
}

matrix invertmatrix(matrix matrix1)
{
    double det = determinant(matrix1);

    if (det == 0)
    {
        cout << "error: matrix cannot be inverted" << endl;
        return {};
    }

    matrix cof = cofactor(matrix1);
    matrix adj = transposematrix(cof);

    int n = matrix1.size();
    matrix result(n, vec(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = adj[i][j] / det;
        }
    }

    return result;
}
