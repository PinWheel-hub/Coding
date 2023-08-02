/*
有效的括号 栈
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
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


