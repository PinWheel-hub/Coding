/*
接雨水 困难
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
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
    int trap(vector<int>& height) {
        vector<int> index(height.size());
        iota(index.begin(), index.end(), 0);
        int ans = 0;
        sort(index.begin(), index.end(), [&](int a, int b) {return height[a] > height[b];});
        int l = index[0], r = index[0];
        int h = 0;
        for(int i = 1; i < index.size(); ++i) {
            if(index[i] < l) {
                h = height[index[i]];
                for(int j = index[i] + 1; j <= l - 1; ++j) {
                    ans += h - height[j];
                }
                l = index[i];
            }
            else if(index[i] > r) {
                h = height[index[i]];
                for(int j = r + 1; j <= index[i] - 1; ++j) {
                    ans += h - height[j];
                }
                r = index[i];                
            }
            else continue;
            if(l < 2 && r > height.size() - 3) break;           
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    cout << sol.trap(nums);
	system("pause");
}


