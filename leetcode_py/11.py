from typing import List, Optional
import sys
import random

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        maxarea = min(height[l], height[r]) * (r - l)
        while l < r:
            if height[l] > height[r]:
                h_r = height[r]
                while r > l:
                    r -= 1
                    if height[r] > h_r:
                        break
                if min(height[l], height[r]) * (r - l) > maxarea:
                    maxarea = min(height[l], height[r]) * (r - l)
            else:
                h_l = height[l]
                while r > l:
                    l += 1
                    if height[l] > h_l:
                        break
                if min(height[l], height[r]) * (r - l) > maxarea:
                    maxarea = min(height[l], height[r]) * (r - l)
        return maxarea
if __name__ == '__main__':
    height = [1,8,6,2,5,4,8,3,7]
    sol = Solution()
    print(sol.maxArea(height))