"""
66. Plus One

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
"""

class Solution:
    def plusOne(self, digits):
        plus = False
        res = []
        for x in digits[::-1]:
            if plus:
                res.append(x)
                continue
            if x != 9:
                res.append(x+1)
                plus = True
            else:
                res.append(0)
        if not plus:
            res.append(1)
        return res[::-1]

def main():
    digits = [[1, 2, 3], [4, 9, 9, 9], [9, 9, 9, 9]]
    for digit in digits:
        print(Solution().plusOne(digit))

if __name__ == "__main__":
    main()