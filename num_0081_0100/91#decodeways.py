"""
91. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.
"""

class Solution:
    def numDecodings(self, s) :
        if s == '':
            return 1

        if s[0] == '0':
            return 0

        possibleDouble = True if self.isPossibleDouble(s[:2]) else False

        if possibleDouble:
            return self.numDecodings(s[1:]) + self.numDecodings(s[2:])
        else:
            return self.numDecodings(s[1:])

    def isPossibleDouble(self, num):
        return len(num) == 2 and (num[0] == '1' or (num[0] == '2' and num[1] <= '6'))

    def numDecodings_dp(self, s):
        if not s:
            return 0

        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        
        for i in range(1, n + 1):
            if s[i-1] != '0':
                dp[i] += dp[i-1]
            if len(s[i-2:i]) == 2 and '10' <= s[i-2:i] <= '26':
                dp[i] += dp[i-2]

        return dp[n]



def main():
    s = "226"
    print(Solution().numDecodings(s))

if __name__ == "__main__":
    main()