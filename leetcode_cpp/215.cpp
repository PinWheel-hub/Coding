/*
数组中的第K个最大元素 堆排序/快速排序
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
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
    int findKthLargest(vector<int>& nums, int k) {
        function<int(int, int)> partition = [&](int l, int r) -> int {
            if(l == r)
                return l;
            int index = rand() % (r - l) + l;
            swap(nums[index], nums[r]);
            int j = l - 1;
            for(int i = l; i < r; ++i) {
                if(nums[i] < nums[r]) {
                    swap(nums[++j], nums[i]);
                }
            }
            swap(nums[j + 1], nums[r]);
            return j + 1;
        };
        function<int(int, int)> findk = [&](int l, int r) -> int {
            int divide = partition(l, r);
            if(divide == nums.size() - k) {
                return nums[divide];
            }
            return divide > nums.size() - k ? findk(l, divide - 1) : findk(divide + 1, r);
        };
        srand(9);
        return findk(0, nums.size() - 1);
    }
};

int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
	Solution sol;
    cout << sol.findKthLargest(nums, 4) << endl;
	system("pause");
}


