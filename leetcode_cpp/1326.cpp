/* 
灌溉花园的最少水龙头数目 动态规划
在 x 轴上有一个一维的花园。花园长度为 n，从点 0 开始，到点 n 结束。
花园里总共有 n + 1 个水龙头，分别位于 [0, 1, ..., n] 。
给你一个整数 n 和一个长度为 n + 1 的整数数组 ranges ，其中 ranges[i] （下标从 0 开始）表示：如果打开点 i 处的水龙头，可以灌溉的区域为 [i -  ranges[i], i + ranges[i]] 。
请你返回可以灌溉整个花园的 最少水龙头数目 。如果花园始终存在无法灌溉到的地方，请你返回 -1 。
 */
using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>

class Solution {
public:
	int minTaps(int n, vector<int>& ranges) {
		vector<int> dp(n + 1);
		for (int i = 0; i <= n; i++)
		{
			if (ranges[i] == 0)
				continue;
			int start = max(i - ranges[i], 0);
			int end = min(i + ranges[i], n);
			if (start != 0 && dp[start] == 0)
				continue;
			if(start == 0)
				for (int j = start; j <= end; j++)
				{
					dp[j] = 1;
				}
			else
				for (int j = start; j <= end; j++)
				{
					if (dp[j] == 0)
						dp[j] = dp[start] + 1;
					else
						dp[j] = min(dp[j], dp[start] + 1);
				}
		}
		if (dp[n] == 0)
			return -1;
		else
			return dp[n];
	}
};

int main()
{
	int n = 5;
	vector<int> ranges = { 3,4,1,1,0,0 };
	Solution a;
	cout << a.minTaps(n, ranges) << endl;
	system("pause");
}
