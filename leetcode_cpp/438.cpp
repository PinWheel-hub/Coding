/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
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
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for(auto c : p) need[c]++;
        vector<int> ans = {};
        int left = 0, right = 0, valid = 0;
        while(right < s.size()) {
            char c = s[right];
            if(need.count(c)) {
                window[c]++;
                if(window[c] == need[c]) {
                    valid++;
                }
            }
            right++;
            while(right - left >= p.size()) {
                if(valid == need.size()) {
                    ans.push_back(left);
                }
                c = s[left];
                if(need.count(c)) {                 
                    if(window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
                left++;
            }
            
        }
        return ans;
    }
};

int main()
{
    string s = "cbaebabacd", p = "abc";
	Solution sol;
    vector<int> ans = sol.findAnagrams(s, p);
    for(auto num : ans) {
        cout << num << endl;
    }
    cout << endl;
	system("pause");
}


