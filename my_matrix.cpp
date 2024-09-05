using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <functional>

#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct Matrix
{
    T *M;
    int rows, cols;
    Matrix() {
        rows = -1;
        cols = -1;
        M = NULL;
    }
    Matrix(int _rows, int _cols) {
        rows = _rows;
        cols = _cols;
        M = new T[((long int)rows) * cols];
    }
    T *operator[](int i) { 
        return M + (((long int)i) * cols);
    }
    ~Matrix() {
        if (M != NULL) delete[] M;
        M = NULL;
    }
};

int main()
{
    Matrix<int> mat(3, 3);
    // 给矩阵中的元素赋值
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[0][2] = 3;
    mat[1][0] = 4;
    mat[1][1] = 5;
    mat[1][2] = 6;
    mat[2][0] = 7;
    mat[2][1] = 8;
    mat[2][2] = 9;
    // 访问并打印矩阵中的元素
    cout << "Matrix element at (1,2): " << mat[1][2] << endl; // 输出6
    // 修改某个元素的值
    mat[1][2] = 42;
    cout << "Matrix element at (1,2) after modification: " << mat[1][2] << endl; // 输出 42
    return 0;
}