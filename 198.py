from typing import List, Optional
import sys
import random

class Solution:
    def rob(self, nums: List[int]) -> int:
        choose = nums[0]
        not_choose = 0
        for i in range(1, len(nums)):
            temp = not_choose
            not_choose = max(choose, not_choose)
            choose = temp + nums[i]
        return max(choose, not_choose)
            
            

if __name__ == '__main__':
    nums = [2,7,9,3,1]
    sol = Solution()
    print(sol.rob(nums))