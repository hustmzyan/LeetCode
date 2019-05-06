"""
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
"""
def trap(height):
    size = len(height)
    if size == 0:
        return 0
    ans = 0
    left_max = []
    right_max = []
    left_max.append(height[0])
    for i in range(1, size):
        left_max.append(max(height[i], left_max[i - 1]))
    right_max.append(height[size - 1])
    for i in range(1, size):
        right_max.append(max(height[size - 1 - i], right_max[i - 1]))
    for i in range(1, size - 1):
        ans = ans + min(left_max[i], right_max[-i - 1]) - height[i]
    return ans
    

def trap_brutal_force(height):
    ans = 0
    for i in range(1, len(height)):
        max_left = 0
        max_right = 0
        for j in range(0, i+1):
            # print("for:", i-j)
            max_left = max(max_left, height[i - j])
        for j in range(i, len(height)):
            max_right = max(max_right, height[j])
        ans = ans + min(max_left, max_right) - height[i]
    return ans
        

def main():
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    # height = [2, 0, 2]
    area = trap(height)
    print(area)

if __name__ == '__main__':
    main()