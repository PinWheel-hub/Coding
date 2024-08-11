/*
下一个排列 中等
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。
必须 原地 修改，只允许使用额外常数空间。
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
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> set;
        vector<vector<int>> subarray;
        int l = -1, r = -1; 
        for(int x = 0; set.size() < len; ++x) {
            bool flag = true;
            for(int i = len - 1 - x; i >= 0; --i) {
                if(set.count(i)) {
                    continue;
                }
                if(flag) {
                    subarray.push_back({i});
                    flag = false;
                    set.insert(i);
                    continue;
                }
                if(nums[i] >= nums[subarray[x].back()]) {
                    continue;
                }
                set.insert(i);
                if(i > l) {
                    r = subarray[x].back();
                    l = i;
                }
                subarray[x].push_back(i);
            }
        }
        cout << l << " " << r << endl;
        if(l > -1) swap(nums[l], nums[r]);
        if(l < (int)nums.size() - 1) sort(nums.begin() + l + 1, nums.end(), [](int a, int b) {return a < b;});
    }
};

int main()
{
    vector<int> nums = {3,2,1};
	Solution sol;
	sol.nextPermutation(nums);
    for(const auto& num : nums)
        cout << num << " ";
    cout << endl;
	system("pause");
}


