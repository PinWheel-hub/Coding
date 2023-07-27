from typing import List, Optional
import sys

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        return headA

def print_listnode(head: ListNode):
    while head != None:
        print(head.val, end=" ")
        head = head.next
    print()
    
if __name__ == '__main__':
    headC = ListNode(8)
    headC.next = ListNode(4)
    headC.next.next = ListNode(5)

    headA = ListNode(4)
    headA.next = ListNode(1)
    headA.next.next = headC

    headB = ListNode(5)
    headB.next = ListNode(6)
    headB.next.next = headC

    sol = Solution()
    head = sol.getIntersectionNode(headA, headB)
    print_listnode(headA)