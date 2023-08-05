/*
不同路径 动态规划
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
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
    void sortColors(vector<int>& nums) {
        vector<int> num012(3);
        for(auto num : nums) {
            num012[num]++;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(i < num012[0]) {
                nums[i] = 0;
            }
            else if(i < num012[0] + num012[1]) {
                nums[i] = 1;
            }
            else {
                nums[i] = 2;
            }
        }
    }
};

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
	Solution sol;
    sol.sortColors(nums);
    for(auto num : nums) {
        cout << num << " ";
    }
	system("pause");
}


