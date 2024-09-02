/*
缺失的第一个正数 困难
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
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
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // for(const auto& num : nums) {
        //     cout << num << " ";
        // }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i] - 1] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main()
{
    cout << endl;
	system("pause");
}


