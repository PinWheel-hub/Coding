/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
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

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> times(grid.size(), vector<int> (grid[0].size(), 0));
        queue<pair<int, int>> q;
        int time = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    times[i][j] = -1;
                } 
            }
        }
        auto is_valid = [&](int i, int j) -> bool {
            return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && times[i][j] == 0 && grid[i][j] != 0;
        };
        while(!q.empty()) {
            int i = q.front().first, j = q.front().second;
            int current_time = max(0, times[i][j]);
            grid[i][j] = 2;
            if(is_valid(i - 1, j)) {
                q.push(make_pair(i - 1, j));
                times[i - 1][j] = current_time + 1;
            }
            if(is_valid(i + 1, j)) {    
                q.push(make_pair(i + 1, j));
                times[i + 1][j] = current_time + 1;
            }
            if(is_valid(i, j - 1)) {
                q.push(make_pair(i, j - 1));
                times[i][j - 1] = current_time + 1;
            }
            if(is_valid(i, j + 1)) {
                q.push(make_pair(i, j + 1));
                times[i][j + 1] = current_time + 1;
            }
            q.pop();
        }
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1) return -1;
                if(times[i][j] > time) time = times[i][j];
            }
        }
        return time;
    }
};

int main()
{
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    Solution sol;
    cout << sol.orangesRotting(grid) << endl;
	system("pause");
}


