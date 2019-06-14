"""
58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ls = s.strip(' ').split(' ')
        print(ls)
        return len(ls[len(ls)-1])

def main():
    s = 'a b  abc   '
    print(Solution().lengthOfLastWord(s))

if __name__ == "__main__":
    main()