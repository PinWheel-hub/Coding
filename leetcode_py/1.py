from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i, num in enumerate(nums):
            if target - num in map:
                return [map[target - num], i]
            map[num] = i
        return []
if __name__ == '__main__':
    nums = [2,7,11,15]
    target = 9
    sol = Solution()
    print(sol.twoSum(nums, target))