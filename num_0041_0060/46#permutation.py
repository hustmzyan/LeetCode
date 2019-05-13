"""
46. Permutations

Given a collection of distinct integers, return all possible permutations.
"""

def permute(nums):
    return [[n] + p
            for i, n in enumerate(nums)
            for p in permute(nums[:i] + nums[i+1:])] or [[]]

def main():
    nums = [1, 3, 2]
    print(permute(nums))

if __name__ == "__main__":
    main()