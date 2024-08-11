/*
和为 K 的子数组 子串
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
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

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int out = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            auto it = map.find(sum - k);
            if(it != map.end()) {
                out += it -> second;
            }
            map[sum]++;
        }
        return out;
    }
};

int main()
{
	vector<int> nums = {1,2,3};
    int k = 3;
	Solution sol;
	cout << sol.subarraySum(nums, k) << endl;
	// for(auto num : nums) {
	// 	cout << num << " ";
	// }
	// cout << endl;
	system("pause");
}
