# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
# 
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.
# 
# Example:
# 
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.

# Definition for singly-linked list.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ret = ListNode(0)
        current = ret
        carry = 0
        while((l1 is not None) or (l2 is not None)):
            x = l1.val if l1 is not None else 0
            y = l2.val if l2 is not None else 0
            sum = carry + x + y
            carry = int(sum / 10)

            current.next = ListNode(sum%10)
            current = current.next

            l1 = l1.next if l1 is not None else l1
            l2 = l2.next if l2 is not None else l2
        
        if(carry > 0):
            current.next = ListNode(carry)

        return ret.next

if __name__ == "__main__":
    s = Solution()
    l1_node0 = ListNode(2)
    l1_node1 = ListNode(4)
    l1_node2 = ListNode(3)
    l1_node0.next = l1_node1
    l1_node1.next = l1_node2

    l2_node0 = ListNode(5)
    l2_node1 = ListNode(6)
    l2_node2 = ListNode(4)
    l2_node0.next = l2_node1
    l2_node1.next = l2_node2

    ret = s.addTwoNumbers(l1_node0, l2_node0)
    print(ret.val)
    print(ret.next.val)
    print(ret.next.next.val)
    