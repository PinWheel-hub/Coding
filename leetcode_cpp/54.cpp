/*
螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<vector<bool>> used(matrix.size(), vector<bool> (matrix[0].size(), false));
        int i = 0, j = 0;
        int direction = 0;
        bool flag = true;
        while(flag) {
            cout << matrix[i][j] << endl;
            ans.push_back(matrix[i][j]);
            used[i][j] = true;
            switch(direction) {
                case 0:
                    if(j + 1 >= matrix[i].size() || used[i][j + 1] == true) {
                        if(i + 1 >= matrix.size() || used[i + 1][j] == true) {
                            flag = false;
                        }
                        else {
                            i++;
                            direction = (direction + 1) % 4;
                        }
                    }
                    else {
                        j++;
                    }
                    break;
                case 1:
                    if(i + 1 >= matrix.size() || used[i + 1][j] == true) {
                        if(j - 1 < 0 || used[i][j - 1] == true) {
                            flag = false;
                        }
                        else {
                            j--;
                            direction = (direction + 1) % 4;
                        }
                    }
                    else {
                        i++;
                    }
                    break;
                case 2:
                    if(j - 1 < 0 || used[i][j - 1] == true) {
                        if(i - 1 < 0 || used[i - 1][j] == true) {
                            flag = false;
                        }
                        else {
                            i--;
                            direction = (direction + 1) % 4;
                        }
                    }
                    else {
                        j--;
                    }
                    break;
                case 3:
                    if(i - 1 < 0 || used[i - 1][j] == true) {
                        if(j + 1 >= matrix[i].size() || used[i][j + 1] == true) {
                            flag = false;
                        }
                        else {
                            j++;
                            direction = (direction + 1) % 4;
                        }
                    }
                    else {
                        i--;
                    }
                    break;
                default: break;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	Solution sol;
    vector<int> ans = sol.spiralOrder(matrix);
    for(auto n : ans) {
        cout << n << " ";
    }
    cout << endl;
	system("pause");
}


