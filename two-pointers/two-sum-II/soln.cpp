#include <iostream>
#include <ostream>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    int index_one = 0;
    int index_two = numbers.size() - 1;

    while (true) {
      int sum = numbers[index_one] + numbers[index_two];
      if (sum == target) {
        break;
      }

      if (sum < target) {
        index_one++;
      } else {
        index_two--;
      }
    }

    return {index_one + 1, index_two + 1};
  }
};

int main() {
  std::vector numbers = {-1, 0};
  int target = -1;
  Solution *soln = new Solution;
  std::vector res = soln->twoSum(numbers, target);
  std::cout << res[0] << ", " << res[1] << std::endl;
}
