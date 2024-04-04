from typing import List, Optional
import sys

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        used = [False] * len(nums)
        def dfs(used: List[bool], get: List[int]): 
            for i, num in enumerate(nums):
                if not used[i]:
                    get.append(num)
                    used[i] = True
                    dfs(used, get)
                    get.pop(-1)
                    used[i] = False
            if(len(get) == len(nums)):
                result.append(get[:])
        dfs(used, [])
        return result

if __name__ == '__main__':
    nums = [1, 2, 3, 4]
    sol = Solution()
    print(sol.permute(nums))