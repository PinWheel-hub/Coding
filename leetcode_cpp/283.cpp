/*
移动零 双指针
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。
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

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
// 		int num_0 = 0;
// 		for(int i = 0; i < nums.size() - num_0; ++i) {
// 			if(nums[i] == 0) {
// 				nums.erase(nums.begin() + i);
// 				nums.push_back(0);
// 				--i;
// 				++num_0;
// 			}
// 		}
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int j = 0;
		for(int i = 0; i < nums.size(); ++i) {
			if(nums[i] != 0) {
				nums[j] = nums[i];
				j++;
			}
		}
		fill(nums.begin() + j, nums.end(), 0);
    }
};

int main()
{
	vector<int> nums = {0,1,0,3,12};
	Solution sol;
	sol.moveZeroes(nums);
	for(auto num : nums) {
		cout << num << " ";
	}
	cout << endl;
	system("pause");
}
