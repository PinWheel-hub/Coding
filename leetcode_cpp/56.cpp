/*
合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        vector<int> current = intervals[0];
        for(const auto& interval : intervals) {
            if(interval[0] > current[1]) {
                ans.push_back(current);
                current = interval;
            }
            else {
                current[1] = max(current[1], interval[1]);
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


