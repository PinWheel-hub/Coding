from typing import List, Optional
import sys
import random

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quick(l, r):
            if l == r:
                return l
            index = random.randint(l, r)
            nums[index], nums[r] = nums[r], nums[index]
            j = l - 1
            for i in range(l, r):
                if nums[r] > nums[i]:
                    j += 1
                    nums[j], nums[i] = nums[i], nums[j]
                i += 1
            nums[j + 1], nums[r] = nums[r], nums[j + 1]
            return j + 1
        def findk(l, r):
            q = quick(l, r)
            if q == len(nums) - k:
                return nums[q]
            return findk(l, q - 1) if q > len(nums) - k else findk(q + 1, r)
        random.seed(0)
        return findk(0, len(nums) - 1)

if __name__ == '__main__':
    nums = [3,2,3,1,2,4,5,5,6]
    sol = Solution()
    print(sol.findKthLargest(nums, 4))