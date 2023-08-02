/*
数组中的第K个最大元素 堆
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
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
#include<functional>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> match;
        match[')'] = '(';
        match[']'] = '[';
        match['}'] = '{';
        for(auto c : s) {
            if(st.empty()) {
                st.push(c);
            }
            else if(match.find(c) != match.end() && match[c] == st.top()) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main()
{
    string s = "()[]{}";
	Solution sol;
    cout << sol.isValid(s) << endl;
	system("pause");
}


