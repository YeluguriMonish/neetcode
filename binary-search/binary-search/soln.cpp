#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = low + (high - low) / 2;
    while (low <= high) {
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
      mid = low + (high - low) / 2;
    }
    return -1;
  }
};

int main() {
  vector<int> nums = {1, 0, 3, 5, 9, 12};
  int target = 2;

  Solution *soln = new Solution();
  int res = soln->search(nums, target);
  printf("res: %d\n", res);
}
