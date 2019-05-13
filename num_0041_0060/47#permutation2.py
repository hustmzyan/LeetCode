"""
47. Permutations 2
"""

def permute(nums):
    return [[n] + p
            for i, n in enumerate(nums)
            for p in permute(nums[:i] + nums[i + 1:])] or [[]]

def permuteUnique(nums):
    res = []
    for l in permute(nums):
        if l not in res:
            res.append(l)
    return res

def main():
    nums = [1, 1, 2]
    print(permuteUnique(nums))

if __name__ == "__main__":
    main()