"""
144. Binary Tree Preorder Traversal
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def preorderTraversal(self, root):
        if not root:
            return []
        result, stack = [], [(root, False)]
        while stack:
            cur, visited = stack[-1]
            if not visited:
                result.append(cur.val)
                if cur.left:
                    stack.append((cur.left, False))
                else:
                    stack.pop()
                    stack.append((cur, True))
            elif visited:
                stack.pop()
                if cur.right:
                    stack.append((cur.right, False))
                elif stack:
                    curr = stack.pop()[0]
                    stack.append((curr, True))          
        return result

def main():
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node1.right = node2
    node2.left = node3
    print(Solution().preorderTraversal(node1))

if __name__ == "__main__":
    main()