from typing import List

# class Solution:
#     def moveZeroes(self, nums: List[int]) -> None:
#         op = 0
#         i = 0
#         while(op < len(nums)):
#             op += 1
#             if nums[i] == 0:
#                 del nums[i]
#                 nums.append(0)
#             else:
#                 i += 1
#             if op >= len(nums):
#                 break

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        j = 0
        for i, num in enumerate(nums):
            if num != 0:
                nums[j] = num
                j += 1
        nums[j :] = [0] * (len(nums) - j) 

if __name__ == '__main__':
    nums = [0,1,0,3,12]
    sol = Solution()
    sol.moveZeroes(nums)
    print(nums)