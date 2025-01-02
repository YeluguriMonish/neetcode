from typing import List


class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        encountered = set({})
        for num in nums:
            if num in encountered:
                return True

            encountered.add(num)

        return False


if __name__ == "__main__":
    soln = Solution()
    nums = [1, 2, 3, 3]
    print(soln.hasDuplicate(nums))
