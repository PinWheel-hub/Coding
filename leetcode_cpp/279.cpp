/*
完全平方数 medium
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
*/
using namespace std;
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>

class Solution {
public:
    int numSquares(int n) {
        int len = pow(n, 0.5);
        vector<int> squares(n + 1);
        vector<int> s(len);
        for(int i = 0; i < len; ++i) {
            squares[pow(i + 1, 2)] = 1;
            s[i] = pow(i + 1, 2);
        }
        for(int i = 0; i < len; ++i) {
            squares[pow(i + 1, 2)] = 1;
        }
        for(int i = 1; i < squares.size(); ++i) {
            if(squares[i] > 0) continue;
            squares[i] = INT_MAX;
            for(int j = 0; j < len && s[j] < i; ++j) {
                squares[i] = min(squares[i], squares[i - s[j]] + 1);
            }
        }
        return squares[n];
    }
};

int main()
{
    int n = 12;
    Solution sol;
    cout << sol.numSquares(n) << endl;
	system("pause");
}