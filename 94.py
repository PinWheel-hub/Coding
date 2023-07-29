from typing import List, Optional
import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root == None:
            return []
        out = []
        out.extend(self.inorderTraversal(root.left))
        out.append(root.val)
        out.extend(self.inorderTraversal(root.right))
        return out

if __name__ == '__main__':
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    sol = Solution()
    out = sol.inorderTraversal(root)
    print(out)