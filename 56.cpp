/*
滑动窗口最大值 单调队列 hard
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。
*/
using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) {return a[0] < b[0];});
        vector<int> current = intervals[0];
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] > current[1]) {
                ans.push_back(current);
                current = intervals[i];
            }
            else {
                current[1] = max(current[1], intervals[i][1]);
            }
        }
        ans.push_back(current);
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1,4},{0,4}};
	Solution sol;
    vector<vector<int>> ans = sol.merge(intervals);
    for(auto interval : ans) {
        for(auto num : interval) {
            cout << num << " ";
        }
        cout << endl;
    }
	system("pause");
}


