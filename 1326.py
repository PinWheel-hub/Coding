from typing import List, Optional
import sys
import random
import collections

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        map = {}
        index = 0
        for str in strs:
            count = [0] * 26
            for c in str:
                count[ord(c) - ord("a")] += 1
            if tuple(count) in map:
                ans[map[tuple(count)]].append(str)
            else:
                map[tuple(count)] = index
                ans.append([str])
                index += 1
        return ans

if __name__ == '__main__':
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    sol = Solution()
    print(sol.groupAnagrams(strs))