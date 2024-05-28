#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {

    int low = 0;
    int high = nums.size() - 1;
    int mid = high / 2;
    int res = -1;

    while (low <= high) {
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] >= nums[low]) {
        if (target >= nums[low] && target < nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (target > nums[mid] && target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }

      mid = low + (high - low) / 2;
    }

    return res;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  int target = 4;

  Solution *soln = new Solution();
  int res = soln->search(nums, target);
  cout << "result: " << res << endl;
}
