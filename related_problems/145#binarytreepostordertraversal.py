"""
145. Binary Tree Postorder Traversal
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def postorderTraversal(self, root):
        """
        采用标志位的方法：
            - 0 -> 左右子树未遍历
            - 1 -> 左子树已遍历，右子树未被遍历
            - 2 -> 左右子树已遍历
        """
        if not root:
            return []
        result, stack = [], [[root, 0]]
        while stack:
            cur, visited = stack[-1]
            if visited == 0:
                if cur.left:
                    stack.append([cur.left, 0])
                else:
                    stack.pop()
                    stack.append([cur, 1])
            elif visited == 1:
                if cur.right:
                    stack.append([cur.right, 0])
                else:
                    stack.pop()
                    stack.append([cur, 2])
            else:
                result.append(cur.val)
                stack.pop()
                if stack:
                    stack[-1][-1] += 1

        return result

def main():
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node1.right = node2
    node2.left = node3
    print(Solution().postorderTraversal(node1))

if __name__ == "__main__":
    main()