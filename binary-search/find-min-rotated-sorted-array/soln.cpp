#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int findMin(vector<int> &nums) {

    int low = 0;
    int high = nums.size() - 1;
    int mid = (high - low) / 2;

    int res = 5001;

    while (low <= high) {
      cout << "low: " << low << " high: " << high << " mid: " << mid << endl;
      res = min(nums[mid], res);

      if (nums[mid] > nums[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }

      mid = low + (high - low) / 2;
    }

    return res;
  }
};

int main() {
  vector<int> nums = {11,13,15,17};
  Solution *soln = new Solution();
  int res = soln->findMin(nums);
  cout << "result: " << res << endl;
}
