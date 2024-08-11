/*
二叉树的层序遍历 BFS
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
*/
using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<cmath>
#include<queue>
#include<stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        unordered_map<TreeNode*, int> level;
        queue<TreeNode*> q;
        if(root == nullptr)
            return out;
        q.push(root);
        level[root] = 0;
        while(!q.empty()) {
            if(out.size() <= level[q.front()]) {
                out.push_back(vector<int>());
            } 
            out[level[q.front()]].push_back(q.front()->val);
            if(q.front()->left) {
                q.push(q.front()->left);
                level[q.back()] = level[q.front()] + 1;
            }
            if(q.front()->right) {
                q.push(q.front()->right);
                level[q.back()] = level[q.front()] + 1;
            }
            q.pop();           
        }
        return out;
    }
};
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

	Solution sol;
	vector<vector<int>> out = sol.levelOrder(root);
    for(auto level : out) {
        for(auto num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
	cout << endl;
	system("pause");
}


