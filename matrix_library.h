#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

#include <vector>

using namespace std;

typedef vector<double> vec;
typedef vector<vec> matrix;

// Matrix operations
matrix addmatrices(matrix matrix1, matrix matrix2);
matrix subtractmatrices(matrix matrix1, matrix matrix2);
matrix scalarmultiply(matrix matrix1, double k);
matrix multiplymatrices(matrix matrix1, matrix matrix2);
matrix transposematrix(matrix matrix1);
matrix get_minor(matrix m, int col);
double determinant(matrix matrix1);
matrix cofactor(matrix m);
matrix invertmatrix(matrix matrix1);

// Vector operations
vec addvectors(vec a, vec b);
vec subtract(vec a, vec b);
vec scalarmultiply(vec a, double k);
double dotproduct(vec a, vec b);
vec crossproduct(vec a, vec b);
double magnitude(vec a);
vec normalize(vec a);

#endif