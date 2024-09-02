/*
前 K 个高频元素 medium
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
*/
using namespace std;
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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); ++i) {
            ++hash[nums[i]];
        }
        vector<pair<int, int>> Frequent(hash.size());
        int i = 0;
        for(const auto& p : hash) {
            Frequent[i] = make_pair(p.first, p.second);
            ++i;
        }
        sort(Frequent.begin(), Frequent.end(), [&](pair<int, int> a, pair<int, int> b) {return a.second > b.second;});
        for(int i = 0; i < min(int(Frequent.size()), k); ++i) {
            ans.push_back(Frequent[i].first);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);
    for(const auto& num : ans) cout << num << " ";
    cout << endl;
	system("pause");
}


