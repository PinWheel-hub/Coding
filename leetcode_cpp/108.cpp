/*
将有序数组转换为二叉搜索树 简单
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
*/
using namespace std;
#include<vector>
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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* ans;
    function<void(TreeNode*&, int, int)> dfs = [&](TreeNode*& node, int l, int r) {
      if(r - l < 0) {
        return;
      }
      int middle = (l + r) / 2;
      node = new TreeNode(nums[middle]);
      dfs(node->left, l, middle - 1);
      dfs(node->right, middle + 1, r);
    };
    dfs(ans, 0, nums.size() - 1);
    return ans;
  }
};
int main()
{
    cout << endl;
	system("pause");
}


