/*
长度为 3 的不同回文子序列 medium
给你一个字符串 s ，返回 s 中 长度为 3 的不同回文子序列 的个数。
即便存在多种方法来构建相同的子序列，但相同的子序列只计数一次。
回文 是正着读和反着读一样的字符串。
子序列 是由原字符串删除其中部分字符（也可以不删除）且不改变剩余字符之间相对顺序形成的一个新字符串。
例如，"ace" 是 "abcde" 的一个子序列。
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
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        unordered_map<char, vector<int>> hash;
        for(int i = 0; i < s.size(); ++i) {
            hash[s[i]].push_back(i);
        }
        for(const auto& dic : hash) {
            if(dic.second.size() > 1) {
                unordered_set<char> set;
                for(int i = dic.second[0] + 1; i < dic.second[dic.second.size() - 1]; ++i) {
                    if(!set.count(s[i])) {
                        ++ans;
                        set.insert(s[i]);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
	string s = "bbcbaba";
	Solution sol;
	cout << sol.countPalindromicSubsequence(s) << endl;
	// for(auto num : nums) {
	// 	cout << num << " ";
	// }
	// cout << endl;
	system("pause");
}