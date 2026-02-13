#include <iostream>
#include <vector>
#include "matrix_library.h"

using namespace std;

matrix inputMatrix(int rows, int cols)
{
    matrix m(rows, vec(cols));
    cout << "Enter matrix values (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> m[i][j];
        }
    }
    return m;
}

void printMatrix(const matrix &m)
{
    if (m.empty())
        return;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int r1, c1, r2, c2;

    cout << "Enter rows & cols of Matrix A: ";
    cin >> r1 >> c1;
    matrix A = inputMatrix(r1, c1);

    cout << "Enter rows & cols of Matrix B: ";
    cin >> r2 >> c2;
    matrix B = inputMatrix(r2, c2);

    if (r1 == r2 && c1 == c2)
    {
        cout << "A + B:" << endl;
        printMatrix(addmatrices(A, B));

        cout << "A - B:" << endl;
        printMatrix(subtractmatrices(A, B));
    }

    double k;
    cout << "Enter a scalar value (k): ";
    cin >> k;

    cout << "Result of k * A:" << endl;
    printMatrix(scalarmultiply(A, k));
    cout << "Transpose(A):" << endl;
    printMatrix(transposematrix(A));

    if (c1 == r2)
    {
        cout << "A * B:" << endl;
        printMatrix(multiplymatrices(A, B));
    }

    cout << "Enter size of vectors: ";
    int n;
    cin >> n;

    vec v1(n), v2(n);
    cout << "Enter vector 1:" << endl;
    for (int i = 0; i < n; i++)
        cin >> v1[i];

    cout << "Enter vector 2:" << endl;
    for (int i = 0; i < n; i++)
        cin >> v2[i];

    cout << "v1 + v2:" << endl;
    vec v_sum = addvectors(v1, v2);
    for (int i = 0; i < v_sum.size(); i++)
        cout << v_sum[i] << " ";
    cout << endl;

    cout << "Dot product (v1·v2): " << dotproduct(v1, v2) << endl;

    if (n == 3)
    {
        cout << "Cross product:" << endl;
        vec v_cross = crossproduct(v1, v2);
        for (int i = 0; i < 3; i++)
            cout << v_cross[i] << " ";
        cout << endl;
    }

    cout << "Normalize(v1):" << endl;
    vec v_norm = normalize(v1);
    for (int i = 0; i < v_norm.size(); i++)
        cout << v_norm[i] << " ";
    cout << endl;

    if (r1 == c1)
    {
        cout << "Determinant of A: " << determinant(A) << endl;
        if (determinant(A) != 0)
        {
            cout << "Inverse of A:" << endl;
            printMatrix(invertmatrix(A));
        }
    }

    cout << "Program Finished.";
    return 0;
}
