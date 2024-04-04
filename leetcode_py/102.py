from typing import List, Optional
import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        out = []
        queue = []
        level = {}
        queue.append(root)
        level[root] = 0
        while len(queue) > 0:
            if level[queue[0]] >= len(out):
                out.append([])
            out[level[queue[0]]].append(queue[0].val)
            if queue[0].left:
                queue.append(queue[0].left)
                level[queue[0].left] = level[queue[0]] + 1
            if queue[0].right:
                queue.append(queue[0].right)
                level[queue[0].right] = level[queue[0]] + 1
            queue.pop(0)
        return out

if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    sol = Solution()
    out = sol.levelOrder(root)
    print(out)