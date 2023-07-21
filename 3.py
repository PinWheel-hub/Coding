from typing import List

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        start = 0
        end = 0
        dic = {}
        for i, c in enumerate(s):
            end = i
            if c not in dic:
                max_length = max(max_length, end - start + 1)
            else:
                for j in range(start, dic[c]):
                    del dic[s[j]]
                start = dic[c] + 1
            dic[c] = i
        return max_length

if __name__ == '__main__':
    s = 'pwwkew'
    sol = Solution()
    print(sol.lengthOfLongestSubstring(s))