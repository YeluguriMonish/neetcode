from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [1000000] * len(temperatures)
        removed_temps = {}

        while len(temperatures) != 0:
            last_temp_index = len(temperatures) - 1
            last_temp = temperatures.pop()
            for i in range(last_temp+1, 101):
                if i in removed_temps and removed_temps[i] - last_temp_index < res[last_temp_index]:
                    res[last_temp_index] = removed_temps[i] - last_temp_index

            removed_temps[last_temp] = last_temp_index


        for i in range(len(res)):
            if res[i] == 1000000:
                res[i] = 0

        return res

if __name__ == "__main__":
    input = [73,74,75,71,69,72,76,73]

    soln = Solution()
    res = soln.dailyTemperatures(input)
    print(res)
