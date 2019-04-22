# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(0)
        result_tail = result
        carry = 0

        while l1 or l2 or carry:
            val1 = (l1.val if l1 else 0)
            val2 = (l2.val if l2 else 0)
            carry, out = divmod(val1 + val2 + carry, 10)

            result_tail.next = ListNode(out)
            result_tail = result_tail.next

            l1 = (l1.next if l1 else None)
            l2 = (l2.next if l2 else None)

        return result.next

def main():
    x1 = ListNode(2)
    x2 = ListNode(4)
    x3 = ListNode(3)
    y1 = ListNode(5)
    y2 = ListNode(6)
    y3 = ListNode(4)
    x1.next = x2
    x2.next = x3
    y1.next = y2
    y2.next = y3


    result = Solution().addTwoNumbers(x1, y1)

    while result:
        print(result.val)
        result = result.next


if __name__ == '__main__':
    main()