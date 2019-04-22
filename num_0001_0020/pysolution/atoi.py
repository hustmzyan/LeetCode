class Solution:
    def myAtoi(self, str: str) -> int:
        # flag = True
        # first_nag = False
        # num = 0
        # max_num = 2 ** 31
        # min_num = -2 ** 31
        # nage_tag = '-'
        # str = str.replace(" ", "")
        # if len(str) == 0:
        #     return 0
        # for i, c in enumerate(str):
        #     #判断首字符合法？
        #     if i == 1 and not c.isdigit():
        #         return 0
        #     # 首次遇到-，非首次跳过
        #     if c == nage_tag:
        #         if not flag:
        #             continue
        #         flag = False
        #         continue
        #
        #     if num and not c.isdigit():
        #         return num
        #     if c.isdigit():
        #         s = int(c)
        #         if flag == False and first_nag == False:
        #             first_nag = True
        #             num = -s
        #         elif flag == False and first_nag == True:
        #             num = num * 10 - s
        #         elif flag == True:
        #             num = num * 10 + s
        #         if num >= max_num:
        #             return max_num
        #         elif num < min_num:
        #             return min_num
        # return num


        str1 = str.lstrip()
        if len(str1) == 0:
            return 0
        sign = 1
        dig_str = ''
        for i, ch in enumerate(str1):
            if i == 0:
                if not (ch.isdigit() or ch in ['+', '-']):
                    return 0
                elif ch == '-':
                    sign = -1
                    continue
                elif ch == '+':
                    sign = 1
                    continue

            if ch.isdigit():
                dig_str += ch
            else:
                break

        length = len(dig_str)

        num = 0
        for i, ch in enumerate(dig_str):
            num += int(ch) * 10 ** (length - i - 1)

        num = sign * num

        if num > 2 ** 31 - 1:
            return 2 ** 31 - 1
        if num < -2 ** 31:
            return -2 ** 31

        return num




# def main():
#     s = '-91283472332'
#     # print(int(True))
#     print(Solution().myAtoi(s))


if __name__ == '__main__':
    s = '3.14'
    sou = Solution()
    a = sou.myAtoi(s)
    print(a)
