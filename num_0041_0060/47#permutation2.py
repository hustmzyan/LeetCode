"""
47. Permutations 2
"""

def permuteUnique(nums):
    perms = [[]]
    for n in nums:
        perms = [p[:i] + [n] + p[i:]
                    for p in perms
                    for i in range((p + [n]).index(n) + 1)]
    return perms

def main():
    nums = [1, 1, 2, 2]
    print(permuteUnique(nums))

if __name__ == "__main__":
    main()