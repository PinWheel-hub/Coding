from typing import List, Optional
import sys
import random

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        c = 1
        a = 1
        for i in range(0, m - 1):
            c *= m + n - 2 - i
            a *= i + 1
        return int(c / a)
            
if __name__ == '__main__':
    sol = Solution()
    print(sol.uniquePaths(3, 7))