from typing import List, Optional
import sys
import random

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        nearest = len(nums) - 1
        for i in range(len(nums) - 2, -1 , -1):
            if(nums[i] + i >= nearest):
                nearest = i
        return nearest == 0

if __name__ == '__main__':
    nums = [2,3,1,1,4]
    sol = Solution()
    print(sol.canJump(nums))