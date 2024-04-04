using namespace std;
#include<vector>
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
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> path(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < path.size(); ++i) {
            for(int j = 0; j < path[i].size(); ++j) {
                if(i == 0 && j == 0) {
                    path[i][j] = grid[i][j];
                    continue;
                }
                path[i][j] = min(i == 0 ? INT_MAX : path[i - 1][j], j == 0 ? INT_MAX : path[i][j - 1]) + grid[i][j];
            }
        }
        return path[path.size() - 1][path[0].size() - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution sol;
    cout << sol.minPathSum(grid);
    cout << endl;
	system("pause");
}