/*
全排列 回溯
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*/
using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        function<void(vector<bool>, vector<int>)> dfs = [&](vector<bool> used, vector<int> get) -> void {
            for(int i = 0; i < used.size(); ++i) {
                if(!used[i]) {
                    used[i] = true;
                    get.push_back(nums[i]);
                    dfs(used, get);
                    used[i] = false;
                    get.pop_back();
                }
            }
            if(get.size() == nums.size()) {
                result.push_back(get);
            } 
        };
        vector<bool> used(nums.size(), false);
        dfs(used, vector<int>());
        return result;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
	Solution sol;
	vector<vector<int>> result = sol.permute(nums);
    for(auto row : result) {
        for(auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
	cout << endl;
	system("pause");
}


