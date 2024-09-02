/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
using namespace std;
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
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*, long, long)> PreT = [&](TreeNode* t, long min, long max) -> bool {
            if(t == nullptr) return true;
            long node = t->val;
            if(node >= max || node <= min) return false;
            return PreT(t->left, min, node) && PreT(t->right, node, max);
        };
        return PreT(root, LONG_MIN, LONG_MAX);
    }
};

// 根据数组构建二叉树
TreeNode* buildTree(vector<int>& nums, int index) {
    if (index >= nums.size() || nums[index] == -1) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(nums[index]);
    root->left = buildTree(nums, 2 * index + 1);
    root->right = buildTree(nums, 2 * index + 2);
    
    return root;
}

// 层序遍历打印二叉树
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node != nullptr) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
}

int main()
{
    vector<int> nums = {2,2,2};
    TreeNode* t = buildTree(nums, 0);
    // levelOrderTraversal(t);
	Solution sol;
    cout << sol.isValidBST(t) << endl;
	system("pause");
}


