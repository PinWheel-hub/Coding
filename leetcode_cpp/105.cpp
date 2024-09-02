/*
从前序与中序遍历序列构造二叉树 中等
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
*/

using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hash;
        for(int i = 0; i < inorder.size(); ++i) {
            hash[inorder[i]] = i;
        }
        TreeNode* root = new TreeNode();
        function<void(int, int, int, int, TreeNode*)> dfs = [&](int l, int r, int li, int ri, TreeNode* t) {
            if(l <= r) {
                t->val = preorder[l];
                int index = hash[preorder[l]];
                // cout << l << " " << r << endl;
                // cout << li << " " << index << " " << ri << endl;
                
                if(l + 1 <= l + index - li) {
                    TreeNode* tl = new TreeNode();
                    t->left = tl;
                    dfs(l + 1, l + index - li, li, index - 1, tl);
                }
                if(l + index - li + 1 <= r) {
                    TreeNode* tr = new TreeNode();
                    t->right = tr;
                    dfs(l + index - li + 1, r, index + 1, ri, tr);
                }
            }          
        };
        dfs(0, inorder.size() - 1, 0, inorder.size() - 1, root);
        return root;
    }
};

int main()
{
	system("pause");
}