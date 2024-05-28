#include <algorithm>
#include <iostream>
#include <ostream>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    for (int x = 0; x < nums.size() - 2; x++) {

      if (x > 0 && nums[x] == nums[x - 1]) {
        continue;
      }

      int y = x + 1;
      int z = nums.size() - 1;
      while (true) {
        if (y == z) {
          break;
        }

        if (y == x) {
          y++;
          continue;
        }
        if (z == x) {
          z--;
          continue;
        }

        int sum = nums[x] + nums[y] + nums[z];
        if (sum == 0) {
          res.push_back({nums[x], nums[y], nums[z]});
          while (y < z) {
            y++;
            if (nums[y] != nums[y - 1]) {
              break;
            }
          }

          while (z > y) {
            z--;
            if (nums[z] != nums[z + 1]) {
              break;
            }
          }

          continue;
        }

        if (sum <= 0) {
          y++;
          continue;
        }

        if (sum > 0) {
          z--;
          continue;
        }
      }
    }

    return res;
  }
};

int main() {
  Solution *soln = new Solution;
  std::vector<int> nums = {0, 0, 0};
  std::vector<std::vector<int>> res = soln->threeSum(nums);
  for (std::vector v : res) {
    std::cout << "pair: ";
    for (int i : v) {
      std::cout << i << ", ";
    }
    std::cout << std::endl;
  }
}
