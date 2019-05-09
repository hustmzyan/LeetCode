"""
44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
"""


def isMatch(s, p):
    print(s)
    length = len(s)
    if len(p) - p.count('*') > length:
        return False
    dp = [True] + [False] * length
    print('--------------------------------')
    for i in p:
        print(i)
        if i != '*':
            for n in reversed(range(length)):
                dp[n + 1] = dp[n] and (i == s[n] or i == '?')
                print(dp)
        else:
            for n in range(1, length+1):
                dp[n] = dp[n - 1] or dp[n]
                print(dp)
        dp[0] = dp[0] and i == '*'
        print(dp)
        print('---------------------------------')
    return dp[-1]

def main():
    s = 'adceb'
    p = '*a*b'
    ismatch = isMatch(s, p)
    print(ismatch)

if __name__ == "__main__":
    main()