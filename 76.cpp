/*
最小覆盖子串 困难
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
*/
using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        set<array<int, 52>> hash;
        array<int, 52> arr;
        for(auto& num : arr) num = 0;
        for(const auto& c : t) {
            if(c >= 'a') ++arr[c - 'a' + 26];
            else ++arr[c - 'A'];
        }
        hash.insert(arr);
        string ans = "";
        array<int, 52> cur;
        array<int, 52> limit;
        for(auto& num : cur) num = 0;
        for(auto& num : limit) num = 0;
        int l = 0, r = 0;
        int ans_l = 0, ans_r = INT_MAX;
        while(r < s.size()) {
            int num = s[r] >= 'a' ? s[r] - 'a' + 26 : s[r] - 'A';
            ++cur[num];
            if(limit[num] < arr[num]) ++limit[num];
            ++r;
            while(hash.count(limit) && l < r) {
                if(r - l < ans_r - ans_l) {
                    ans_l = l;
                    ans_r = r;
                }
                num = s[l] >= 'a' ? s[l] - 'a' + 26 : s[l] - 'A';
                --cur[num];
                if(cur[num] < arr[num]) --limit[num];
                ++l;
            }
        }
        return ans_r == INT_MAX ? "" : s.substr(ans_l, ans_r - ans_l);
    }
};
int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    Solution sol;
    cout << sol.minWindow(s, t);
	system("pause");
}


