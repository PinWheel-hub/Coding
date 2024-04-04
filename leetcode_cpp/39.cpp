/*
组合总和 中等
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
对于给定的输入，保证和为 target 的不同组合数少于 150 个。
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        function<void(int, vector<int>)> dfs = [&](int t, vector<int> current) {
            for(int i = 0; i < candidates.size(); ++i) {
            }
        };
    }
};

int main()
{
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(candidates, target);

    cout << endl;
	system("pause");
}


