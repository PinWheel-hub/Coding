/*
搜索插入位置 二分搜索
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。
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
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ans = nums.size();
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] >= target) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,3,5,6};
    int target = 5;
	Solution sol;
	int result = sol.searchInsert(nums, target);
    cout << result << endl;
	system("pause");
}


