"""
230. Kth Smallest Element in a BST
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def kthSmallest(self, root, k) :
        """
        树的中序遍历转化为栈来解决
        """
        stack = [(root, False)]
        count = 1

        while stack:
            cur, visited = stack.pop()
            if cur:
                if visited and count == k:
                    return cur.val
                elif visited and count < k:
                    count += 1
                else:
                    stack.append((cur.right, False))
                    stack.append((cur, True))
                    stack.append((cur.left, False))

        return None

def main():
    node1 = TreeNode(3)
    node2 = TreeNode(1)
    node3 = TreeNode(4)
    node4 = TreeNode(2)

    node1.left = node2
    node1.right = node3
    node2.right = node4

    print(Solution().kthSmallest(node1, 1))

if __name__ == "__main__":
    main()