class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        flag = False
        print(x)
        print(2 ** 31)
        print(-2 ** 31)
        if x >= 2 ** 31 :
            return 0
        elif x < -2 ** 31:
            return 0
        if x < 0 :
            flag = True
            x = abs(x)
        while(x):
            result = (int)(result * 10 + x % 10)
            x = (int) (x / 10)
        if flag:
            result = -result
        if result >= 2 ** 31 :
            return 0
        elif result < -2 ** 31:
            return 0
        return result

def main():
    x = 1534236469
    print(Solution().reverse(x))

if __name__ == '__main__':
    main()