from typing import List, Optional
import sys

class Solution:
    def isValid(self, s: str) -> bool:
        match = {")": "(", "]": "[", "}": "{"}
        stack = []
        for c in s:
            if len(stack) == 0:
                stack.append(c)
            elif c in match and match[c] == stack[-1]:
                del stack[-1]
            else:
                stack.append(c)
        return len(stack) == 0 

if __name__ == '__main__':
    s = r"()[]{}"
    sol = Solution()
    print(sol.isValid(s))