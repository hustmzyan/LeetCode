"""
61. Rotate List

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if (head == None):
            return None
        len = 0
        end = node = head
        while (head):
            len += 1
            head = head.next
        step = k % len
        head = node
        for i in range(step):
            end = end.next
        while (end.next):
            node = node.next
            end = end.next
        end.next = head
        head = node.next
        node.next = None
        return head

def main():
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)

    node1.next = node2
    node2.next = node3

    head = Solution().rotateRight(node1, 4)
    # head = node1

    while (head):
        print(head.val, '->', end='')
        head = head.next
    print('NULL')

if __name__ == "__main__":
    main()