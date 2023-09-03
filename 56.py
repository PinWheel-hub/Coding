from typing import List, Optional
import sys
import random

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []
        def sort_key(interval):
            return interval[0]
        intervals = sorted(intervals, key=sort_key, reverse=False)
        current = intervals[0]
        del intervals[0]
        for interval in intervals:
            if current[1] < interval[0]:
                ans.append(current)
                current = interval
            else:
                current[1] = max(current[1], interval[1])
        ans.append(current)
        return ans
    
if __name__ == '__main__':
    intervals = [[1,3],[2,6],[8,10],[15,18]]
    sol = Solution()
    print(sol.merge(intervals))
    print(intervals)