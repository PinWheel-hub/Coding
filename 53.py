from typing import List
import sys

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsub = -sys.maxsize
        minsum = 0
        sum = 0
        for num in nums:
            sum += num
            maxsub = max(maxsub, sum - minsum)
            minsum = min(minsum, sum)
        return maxsub

if __name__ == '__main__':
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    sol = Solution()
    print(sol.maxSubArray(nums))