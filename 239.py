from typing import List, Optional
import sys
import random

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        dq = []
        left = 0
        right = 0
        while right < len(nums):
            while len(dq) > 0 and nums[dq[-1]] <= nums[right]:
                del dq[-1]
            dq.append(right)
            right += 1
            while right - left >= k:
                while dq[0] < left:
                    del dq[0]
                ans.append(nums[dq[0]])
                left += 1
        return ans

if __name__ == '__main__':
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    sol = Solution()
    print(sol.maxSlidingWindow(nums, k))