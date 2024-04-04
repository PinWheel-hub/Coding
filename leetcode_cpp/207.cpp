/*
课程表 medium
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> hash;
        unordered_map<int, int> in;
        for(int i = 0; i < prerequisites.size(); ++i)  {
            hash[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in[prerequisites[i][0]] += 0;
            in[prerequisites[i][1]] += 1;
        }
        if(in.size() > numCourses) return false;
        queue<int> q;
        int ok = 0;
        for(auto dic : in) {
            if(dic.second == 0) {
                q.push(dic.first);
                ++ok;
            }
        }
        while(!q.empty()) {
            int c = q.front();
            for(auto out_c : hash[c]) {
                if(--in[out_c] == 0) {
                    ++ok;
                    q.push(out_c);
                }                
            }
            q.pop();
        }
        return ok == in.size();
    }
};

int main()
{
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    int numCourses = 2;
	Solution sol;
    cout << sol.canFinish(numCourses, prerequisites) << endl;
	system("pause");
}


