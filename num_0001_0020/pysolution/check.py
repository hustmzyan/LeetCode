class Solution:
    def check(self, str1 : str, str2 : str):

        restr = ''
        for c in str2:
            for s in str1:
                if s == c:
                    break
                elif c not in restr:
                    restr = restr + c
        return restr



if __name__ == '__main__':
    s1 = '7_This_is_a_test'
    s2 = '_hs_s_a_es'
    sou = Solution()
    a = sou.check(s1, s2)
    print(a)
