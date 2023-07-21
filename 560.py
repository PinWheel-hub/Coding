from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        dic = {}
        dic[0] = 1
        sum = 0
        out = 0
        for num in nums:
            sum += num
            if sum - k in dic:
                out += dic[sum - k]
            dic[sum] = dic.get(sum, 0) + 1
        return out

if __name__ == '__main__':
    nums = [1, 2, 3]
    k = 3
    sol = Solution()
    print(sol.subarraySum(nums, k))