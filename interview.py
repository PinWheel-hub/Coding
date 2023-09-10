from typing import List, Optional
import sys
import random

class ListNode:
    def __init__(self, x: int = 0, next: Optional['ListNode'] = None):
        self.val = x
        self.next = next

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        q = head
        hash = set()
        while q:
            if q in hash:
                return q
            hash.add(q)
            q = q.next
        return None
    
if __name__ == '__main__':
    head = ListNode(3)
    head.next = ListNode(2)
    head.next.next = ListNode(0)
    head.next.next.next = ListNode(-4)
    head.next.next.next.next = head.next
    sol = Solution()
    print(sol.detectCycle(head).val)