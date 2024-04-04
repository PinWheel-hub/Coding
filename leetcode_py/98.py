from typing import List, Optional
import sys

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def buildTree(nums: List[int], index: int) -> Optional[TreeNode]:
    if index >= len(nums) or nums[index] == -1:
        return None
    root = TreeNode(nums[index])
    root.left = buildTree(nums, 2 * index + 1)
    root.right = buildTree(nums, 2 * index + 2)
    return root


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        max_int = sys.maxsize
        min_int = -sys.maxsize - 1
        def pret(t: Optional[TreeNode], min_int: int, max_int: int) -> bool:
            if t is None:
                return True
            if t.val > min_int and t.val < max_int:
                return pret(t.left, min_int, t.val) and pret(t.right, t.val, max_int)
            else:
                return False
        return pret(root, min_int, max_int)

if __name__ == '__main__':
    root = [2, 1, 3]
    root = buildTree(root, 0)
    sol = Solution()
    print(sol.isValidBST(root))
    