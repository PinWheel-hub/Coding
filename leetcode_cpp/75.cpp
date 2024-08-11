/*
颜色分类
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库内置的 sort 函数的情况下解决这个问题。
*/
using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<cmath>
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


