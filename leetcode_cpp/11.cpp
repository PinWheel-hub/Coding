/*
盛最多水的容器 双指针
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
说明：你不能倾斜容器。
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
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxarea = min(height[l], height[r]) * (r - l);
        while(l < r) {
            if(height[l] > height[r]) {
                int h_r = height[r];
                while(r > l) {
                    if(height[--r] > h_r) {
                        break;
                    }
                }
                if(min(height[l], height[r]) * (r - l) > maxarea) {
                    maxarea = min(height[l], height[r]) * (r - l);
                }
            } else {
                int h_l = height[l];
                while(r > l) {
                    if(height[++l] > h_l) {
                        break;
                    }
                }
                if(min(height[l], height[r]) * (r - l) > maxarea) {
                    maxarea = min(height[l], height[r]) * (r - l);
                }
            }
        }
        return maxarea;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
	Solution sol;
    cout << sol.maxArea(height) << endl;
	system("pause");
}


