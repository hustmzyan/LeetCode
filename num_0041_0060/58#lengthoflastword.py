"""
58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ls = len(s)
        # slow and fast pointers
        slow = -1
        # iterate over trailing spaces
        while slow >= -ls and s[slow] == ' ':
            slow-=1
        fast = slow
        # iterate over last word
        while fast >= -ls and s[fast] != ' ':
            fast-=1
        return slow - fast

def main():
    s = 'a b  abc   '
    print(Solution().lengthOfLastWord(s))

if __name__ == "__main__":
    main()