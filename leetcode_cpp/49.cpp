/*
字母异位词分组 哈希
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
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
    struct ArrayHash {
        size_t operator()(const std::array<int, 26>& arr) const {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ num;
            });
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, int, ArrayHash> map;
        vector<vector<string>> ans;
        int index = 0;
        for(auto str : strs) {
            array<int, 26> count = {0};
            for(auto c : str) {
                count[c - 'a']++;
            }
            if(map.find(count) != map.end()) {
                ans[map[count]].push_back(str);
            }
            else {
                map[count] = index++;
                ans.push_back({str});
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(strs);
    for(auto strings : ans) {
        for(auto str : strings) {
            cout << str << " ";
        }
        cout << endl;
    }
	system("pause");
}


