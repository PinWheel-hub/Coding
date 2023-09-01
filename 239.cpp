/*
滑动窗口最大值 单调队列 hard
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。
*/
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans = {};
        int left = 0, right = 0;
        while(right < nums.size()) {
            while (!q.empty() && nums[right] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(right);
            right++;
            while(right - left >= k) {
                while (q.front() < right - k) {
                    q.pop_front();
                }
                ans.push_back(nums[q.front()]);
                left++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;
	Solution sol;
    vector<int> ans = sol.maxSlidingWindow(nums, k);
    for(auto num : ans) {
        cout << num << endl;
    }
    cout << endl;
	system("pause");
}


