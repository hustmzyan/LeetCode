"""
173. Binary Search Tree Iterator
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BSTIterator:


    def __init__(self, root) :
        self.result, stack = [], [(root, False)]
        self.count = 0

        while stack:
            cur, visited = stack.pop()
            if cur:
                if visited:
                    self.result.append(cur.val)
                else:
                    stack.append((cur.right, False))
                    stack.append((cur, True))
                    stack.append((cur.left, False))

    def next(self) :
        """
        @return the next smallest number
        """
        self.count += 1
        return self.result[self.count - 1]
        

    def hasNext(self):
        """
        @return whether we have a next smallest number
        """
        return self.count < len(self.result)

def main():
    node1 = TreeNode(1)
    node2 = TreeNode(3)
    node3 = TreeNode(2)
    node1.right = node2
    node2.left = node3
    obj = BSTIterator(node1)
    print(obj.next())
    print(obj.next())
    print(obj.next())
    # print(obj.next())
    print(obj.hasNext())
    

if __name__ == "__main__":
    main()