/*
岛屿数量 图论/DFS
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/
using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <stack>
#include <functional>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        auto is_out = [&](int r, int c)->bool {
            return !(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1');
        };
        function<void(int, int)> dfs = [&](int r, int c)->void {
            if(is_out(r, c)) {
                return;
            }
            grid[r][c] = '2';
            dfs(r - 1, c);
            dfs(r + 1, c);
            dfs(r, c - 1);
            dfs(r, c + 1);
        };
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '1') {
                    dfs(i, j);
                    result++;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<char>> grid = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
	Solution sol;
	int out = sol.numIslands(grid);
	cout << out << endl;
	system("pause");
}


