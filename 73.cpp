/*
矩阵置0 
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
*/
using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<math.h>
#include<queue>
#include<stack>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> row;
        unordered_map<int, bool> col;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[i].size(); ++j) {
                if(matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(auto r : row) {
            for(int i = 0; i < matrix[0].size(); ++i) {
                matrix[r.first][i] = 0;
            }
        }
        for(auto c : col) {
            for(int i = 0; i < matrix.size(); ++i) {
                matrix[i][c.first] = 0;
            }
        }
    }
};

int main()
{
	vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
	Solution sol;
	sol.setZeroes(matrix);
	for(auto row : matrix) {
		for(auto element : row) {
		cout << element << " ";
	    }
        cout << endl;
	}
	cout << endl;
	system("pause");
}
