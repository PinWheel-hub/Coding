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
#include<math.h>
#include<queue>
#include<stack>
#include<functional>

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


