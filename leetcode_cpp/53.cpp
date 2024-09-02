/*
最大子数组和 贪心算法/分治法
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。
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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsub = INT_MIN;
        int minsum = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            maxsub = max(maxsub, sum - minsum);
            minsum = min(minsum, sum);
        }
        return maxsub;
    }
};

int main()
{
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	Solution sol;
	cout << sol.maxSubArray(nums) << endl;
	// for(auto num : nums) {
	// 	cout << num << " ";
	// }
	// cout << endl;
	system("pause");
}
