/*
搜索二维矩阵 medium
给你一个满足下述两条属性的 m x n 整数矩阵：
每行中的整数从左到右按非递减顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
*/
using namespace std;
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1;
        while(left <= right) {
            int middle = (left + right) / 2;
            int current = matrix[middle / col][middle % col];
            if(current == target) {
                return true;
            }
            if(current < target) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> nums = {{1, 2}};
    int target = 2;
    Solution sol;
    cout << sol.searchMatrix(nums, target) << endl;
	system("pause");
}


