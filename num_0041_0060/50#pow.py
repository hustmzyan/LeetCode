"""
50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (x^n).

Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
"""

def mypow(x, n):
    if not n:
        return 1
    if n < 0:
        return 1 / mypow(x, -n)
    if n % 2:
        return x * mypow(x, n-1)
    return mypow(x*x, n/2)

def main():
    x = 2.10000
    n = 3
    print(mypow(x, n))

if __name__ == "__main__":
    main()