/*
子集 medium
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> ans;
        ans.push_back({});
        function<void(vector<bool>, vector<int>)> dfs = [&](vector<bool> visited, vector<int> get) -> void {
            if(get.size() >= nums.size()) return;
            for(int i = 0; i < nums.size(); ++i) {
                if(visited[i]) continue;
                visited[i] = true;
                get.push_back(nums[i]);
                ans.push_back(get);
                dfs(visited, get);
                get.pop_back();
            }
        };
        dfs(visited, {});
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> ans = sol.subsets(nums);
    for(const auto& row : ans) {
        for(const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
	system("pause");
}


