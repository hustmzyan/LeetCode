class Solution:
    def maxArea(self, height=[]) -> int:
        n = len(height)
        if n == 2:
            return min(height[0], height[1])
        else:
            l = 0
            r = n - 1
            clh = 0
            crh = 0
            maxa = 0
            while l < r:

                if height[l] < height[r]:
                    maxa = max(height[l] * (r - l), maxa)
                    clh = height[l]
                    while height[l] <= clh:
                        l += 1
                        if l >= r:
                            return maxa

                else:
                    maxa = max(height[r] * (r - l), maxa)
                    crh = height[r]
                    while height[r] <= crh:
                        r -= 1
                        if l >= r:
                            return maxa

            return maxa


if __name__ == "__main__":
    h = [1,2,3,4,5,6]
    maxarea = Solution.maxArea(h)
    print(maxarea)
