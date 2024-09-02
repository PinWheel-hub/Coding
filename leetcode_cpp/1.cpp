/*
两数之和 哈希
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案
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
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i) {
			auto it = map.find(target - nums[i]);
			if(it != map.end()) {
				return {it->second, i};
			}
			map[nums[i]] = i;
		}
		return {};
    }
};

int main()
{
	int target = 6;
	vector<int> nums = {3, 2, 3};
	Solution sol;
	vector<int> outs = sol.twoSum(nums, target);
	for(auto out : outs) {
		cout << out << " ";
	}
	cout << endl;
	system("pause");
}
