/*
跳跃游戏 贪心算法
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
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
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) {
            return true;
        }
        int nearest = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; --i) {
            if(i + nums[i] >= nearest) {
                nearest = i;
            }
        }
        return nearest == 0;
    }
};

int main()
{
    vector<int> nums = {2,3,1,1,4};
	Solution sol;
    cout << sol.canJump(nums) << endl;
	system("pause");
}


