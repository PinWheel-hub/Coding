/*
旋转图像 medium
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/
using namespace std;
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[i].size() - i; ++j) {
                swap(matrix[i][j], matrix[matrix[i].size() - 1 - j][matrix.size() - 1 - i]);
            }
        }
        for(int i = 0; i < matrix.size() / 2; ++i) {
            for(int j = 0; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[matrix.size() - 1 - i][j]);
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution sol;
    sol.rotate(matrix);
    for(const auto& nums : matrix) {
        for(const auto& num : nums) {
        cout << num << " ";
        }
        cout << endl;
    }
	system("pause");
}