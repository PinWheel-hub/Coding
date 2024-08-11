/*
三数之和 medium
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
*/
using namespace std;
#include<vector>
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                if(nums[left] + nums[right] == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                }
                if(nums[left] + nums[right] < target) {
                    while(nums[++left] == nums[left - 1] && left < right) {;}
                }
                else {
                    while(nums[--right] == nums[right + 1] && left < right) {;}
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);
    for(const auto& row : ans) {
        for(const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
	system("pause");
}