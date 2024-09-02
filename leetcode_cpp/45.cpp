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
    int jump(vector<int>& nums) {
        vector<int> min_jump(nums.size(), INT_MAX);
        min_jump[0] = 0;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j <= i + nums[i] && j < nums.size(); ++j) {
                min_jump[j] = min(min_jump[j], min_jump[i] + 1);
            }
        }
        return min_jump[int(nums.size()) - 1];
    }
};

int main() {
    vector<int> nums = {2,3,0,1,4};
    Solution sol;
    cout << sol.jump(nums) << endl;
	system("pause");
}