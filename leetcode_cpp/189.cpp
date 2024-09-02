/*
轮转数组 medium
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
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
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        if(k == 0) return;
        int j = 0;
        int temp1 = nums[(len - k + j) % len];
        int count = len / gcd(k, len);
        int c = 0;
        for(int i = 0; i < len; ++i) {
            int temp2 = nums[j];
            nums[j] = temp1;
            j = (j + k) % len;
            if(++c == count) {
                c = 0;
                ++j;
                temp1 = nums[(len - k + j) % len];
            }
            else
                temp1 = temp2;
        }
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,5,6};
    int k = 4;
    Solution sol;
    sol.rotate(nums, k);
    for(const auto& num : nums) {
        cout << num << " ";
    }
    cout << endl;
	system("pause");
}