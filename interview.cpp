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
    vector<vector<int>> three(vector<int> nums) {
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            unordered_map<int, vector<int>> hash;
            for(int j = 0; j < nums.size(); ++j) {
                if(hash.count(target - nums[j])) {
                    for(const auto& num : hash[target - nums[j]]) {
                        if(i < num) ans.push_back({i, num ,j});
                    }
                }
                hash[nums[j]].push_back(j);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-1, 9, -8, 0, 1, -9, -8, 7};
    Solution sol;
    vector<vector<int>> ans = sol.three(nums);
    for(const auto& row : ans) {
        for(const auto& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
	system("pause");
}