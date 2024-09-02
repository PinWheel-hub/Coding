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
#include <iostream>
#include <vector>
using namespace std;

int dfs(string &s, int &idx)
{
    char preSign = '+';
    stack<int> st;
    auto cal = [&](int num) {
        if (preSign == '+') {
            st.push(num);
        } else if (preSign == '-') {
            st.push(-num);
        } else if (preSign == '*') {
            int val = st.top();
            st.pop();
            st.push(val * num);
        } else if (preSign == '/') {
            int val = st.top();
            st.pop();
            st.push(val / num);
        }
    };
    while (idx < s.size()) {
        if (s[idx] == ' ') {
            ++idx;
        } else if (s[idx] == '(') {
            ++idx;
            cal(dfs(s, idx));
        } else if (s[idx] == ')') {
            ++idx;
            break;
        } else if (s[idx] >= '0' && s[idx] <= '9') {
            int num = 0;
            while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
                num = num * 10 + (s[idx] - '0');
                ++idx;
            }
            cal(num);
        } else {
            preSign = s[idx];
            ++idx;
        }
    }
    int res = 0;
    while (st.size()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int calculate(string s) {
    int idx = 0;
    return dfs(s, idx);
}

int main() {
    cout << calculate("1+1*2");
	system("pause");
}