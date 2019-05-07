"""
43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
"""

def multiply(num1, num2):
    d = {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}
    n1 = num1[::-1]
    n2 = num2[::-1]
    sum1 = 0
    sum2 = 0
    for i in range(len(n1)):
        sum1 += d[n1[i]]*(10**i)
    for i in range(len(n2)):
        sum2 += d[n2[i]]*(10**i)
    return str(sum1*sum2)

def main():
    str1 = "99"
    str2 = "9"
    restr = multiply(str1, str2)
    print(restr)

if __name__ == '__main__':
    main()