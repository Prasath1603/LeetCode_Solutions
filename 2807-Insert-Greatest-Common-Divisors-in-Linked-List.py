# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[Node]) -> Optional[Node]:
        i = head
        while i and i.next:
            a = i.val
            b = i.next.val
            c = gcd(a, b)
            n = Node(c)
            n.next = i.next
            i.next = n
            i = n.next
        return head