from typing import List, Optional
import sys
import random

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        need = [0] * 26
        total = 0
        for c in p:
            if need[ord(c) - ord('a')] == 0:
                total += 1
            need[ord(c) - ord('a')] += 1
        window = [0] * 26
        left = 0
        right = 0
        valid = 0
        ans = []
        while(right < len(s)):
            r = s[right]
            if need[ord(r) - ord('a')] > 0:
                window[ord(r) - ord('a')] += 1
                if window[ord(r) - ord('a')] == need[ord(r) - ord('a')]:
                    valid += 1
            right += 1
            while(right - left >= len(p)):
                if total == valid:
                    ans.append(left)
                l = s[left]
                if need[ord(l) - ord('a')] > 0:
                    if window[ord(l) - ord('a')] == need[ord(l) - ord('a')]:
                        valid -= 1
                    window[ord(l) - ord('a')] -= 1
                left += 1
        return ans

if __name__ == '__main__':
    s = "cbaebabacd"
    p = "abc"
    sol = Solution()
    print(sol.findAnagrams(s, p))