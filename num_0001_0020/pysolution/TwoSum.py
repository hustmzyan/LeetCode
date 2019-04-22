class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        recs = dict((num, i) for i, num in enumerate(nums))

        for i, num in enumerate(nums):
            j = recs.get(target - num)
            if j and not j == i:
                return [i, j]

def main():
    num = [2,7,11,15]
    print(Solution().twoSum(num,9))

if __name__ == '__main__':
    main()