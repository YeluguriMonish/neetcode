from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        start = 0;
        end = len(height) - 1

        max_area = 0
        while start != end:
            current_area = min(height[start], height[end]) * (end - start)

            if height[start] <= height[end]:
                start += 1
            else:
                end -= 1

            if current_area > max_area:
                max_area = current_area

        return max_area

if __name__ == "__main__":
    height = [1, 1]

    soln = Solution()
    res = soln.maxArea(height)
    print(res)
