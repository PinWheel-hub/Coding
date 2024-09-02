/*
最长连续序列 中等
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
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
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int, int>> hash;
        int ans = 0;
        for (const int& num : nums) {
            if(!hash.count(num)) {
                if(hash.count(num - 1) && hash.count(num + 1)) {
                    hash[hash[num - 1].first].second = hash[num + 1].second;
                    hash[hash[num + 1].second].first = hash[num - 1].first;
                    hash[num] = hash[hash[num - 1].first];
                }
                else if(hash.count(num - 1)) {
                    hash[hash[num - 1].first].second = num;
                    hash[num] = hash[hash[num - 1].first];
                }
                else if(hash.count(num + 1)) {
                    hash[hash[num + 1].second].first = num;
                    hash[num] = hash[hash[num + 1].second];
                }
                else {
                    hash[num] = {num, num};
                }
                ans = max(ans, hash[num].second - hash[num].first + 1);
            }
        }
        return ans;           
    }
};

int main()
{
    vector<int> nums = {-5,-5,-4,8,3,1,-4,-6,-7,4,8,-1,8,-3,-8,-9,-7,-3,2,-8,5,-1,3,-8,-6};
    Solution sol;
    cout << sol.longestConsecutive(nums);
	system("pause");
}


