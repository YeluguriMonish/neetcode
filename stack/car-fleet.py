from typing import List


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        position_sorted = []
        for index in range(len(position)):
            position_sorted.append([position[index], speed[index]])

        position_sorted = sorted(position_sorted, key=lambda x: x[0])

        fleet_count = 0
        # while len(position_sorted) != 0:
        #     reached_destination.clear()
        #     for index in range(len(position_sorted)):
        #         position_sorted[index][0] += position_sorted[index][1]

        #     for index in reversed(range(len(position_sorted))):
        #         if index != len(position_sorted) - 1 and position_sorted[index][0] >= position_sorted[index + 1][0]:
        #             if position_sorted[index][0] <= target:
        #                 position_sorted[index][0] = position_sorted[index + 1][0]
        #                 position_sorted[index][1] = position_sorted[index + 1][1]
        #             elif (target - (position_sorted[index][0] - position_sorted[index][1])) / position_sorted[index][1] < (target - (position_sorted[index+1][0] - position_sorted[index+1][1])) / position_sorted[index+1][1]:
        #                 position_sorted[index][0] = position_sorted[index + 1][0]
        #                 position_sorted[index][1] = position_sorted[index + 1][1]

        #     for index in reversed(range(len(position_sorted))):
        #         if position_sorted[index][0] >= target:
        #             car = position_sorted.pop()
        #             if car not in reached_destination:
        #                 reached_destination.append(car)

        #     fleet_count += len(reached_destination)
        reached_destination = []
        while len(position_sorted) != 0:
            reached_destination.clear()
            for index in reversed(range(len(position_sorted))):
                starting_position = position_sorted[index][0]
                distance_to_target = target - starting_position
                position_sorted[index][0] += position_sorted[index][1]

                # if I pass the car in front of me
                if (
                    index != len(position_sorted) - 1
                    and position_sorted[index][0] >= position_sorted[index + 1][0]
                ):
                    if position_sorted[index][0] <= target or (
                        distance_to_target / position_sorted[index][1]
                        < (
                            target
                            - (
                                position_sorted[index + 1][0]
                                - position_sorted[index + 1][1]
                            )
                        )
                        / position_sorted[index + 1][1]
                    ):
                        position_sorted[index][0] = position_sorted[index + 1][0]
                        position_sorted[index][1] = position_sorted[index + 1][1]

                if position_sorted[index][0] >= target:
                    car = position_sorted.pop()
                    if car not in reached_destination:
                        reached_destination.append(car)

            fleet_count += len(reached_destination)

        return fleet_count


if __name__ == "__main__":
    target = 16
    position = [11, 14, 13, 6]
    speed = [2, 2, 6, 7]

    soln = Solution()
    res = soln.carFleet(target, position, speed)
    print(f"result: {res}")
