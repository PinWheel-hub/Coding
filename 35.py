from typing import List, Optional
import sys

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        ans = len(nums)
        while left <= right:
            mid = int((left + right) / 2)
            if nums[mid] >= target:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans 
if __name__ == '__main__':
    nums = [1, 2, 3, 4]
    sol = Solution()
    print(sol.searchInsert(nums, 3))