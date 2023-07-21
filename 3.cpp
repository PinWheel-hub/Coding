/*
无重复字符的最长子串 滑窗
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/
using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<math.h>
#include<queue>
#include<stack>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_map<char, int> map;
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); ++i) {
            end = i;
            auto it = map.find(s[i]);
            if(it == map.end()) {
                max_length = max(end - start + 1, max_length);
            }
            else {
                for(int j = start; j < map[s[i]]; ++j) {
                    map.erase(map.find(s[j]));
                }
                start = map[s[i]] + 1;
            }
            map[s[i]] = i;
        }
        return max_length;
    }
};

int main()
{
	string s = "abcabcbb";
	Solution sol;
	cout << sol.lengthOfLongestSubstring(s) << endl;
	// for(auto num : nums) {
	// 	cout << num << " ";
	// }
	// cout << endl;
	system("pause");
}
