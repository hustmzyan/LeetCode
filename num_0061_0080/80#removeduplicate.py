"""
80. Remove Duplicates from Sorted Array II
"""

class Solution:
    def removeDuplicates(self, nums) -> int:
        count = 0
        pre = 0
        length = 0
        for i, n in enumerate(nums):
            if i == 0:
                pre = n
                count += 1
                length += 1 
            elif n == pre and count < 2:
                count += 1
                length += 1
            elif n == pre and count > 2:
                count = 0
            elif n != pre:
                count = 1
                pre = n
                length += 1
            nums[length - 1] = n
            # print(i, n, count, length)
        return length

def main():
    nums = [0, 0, 1, 1, 1, 1, 2, 3, 3]
    print(Solution().removeDuplicates(nums))

if __name__ == "__main__":
    main()