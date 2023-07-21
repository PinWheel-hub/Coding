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
