from typing import List, Optional
import sys
import random

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        n = [0] * 3
        for num in nums:
            n[num] += 1
        for i, num in enumerate(nums):
            if i < n[0]:
                nums[i] = 0
            elif i < n[0] + n[1]:
                nums[i] = 1
            else:
                nums[i] = 2

if __name__ == '__main__':
    nums = [2,0,2,1,1,0]
    sol = Solution()
    sol.sortColors(nums)
    print(nums)