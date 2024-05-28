#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    vector<int> merged;
    for (vector<int> &m : matrix) {
      merged.insert(merged.end(), m.begin(), m.end());
    }

    int low = 0;
    int high = merged.size() - 1;
    int mid = low + (high - low) / 2;

    while (low <= high) {
      if (merged[mid] == target) {
        return true;
      } else if (merged[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }

      mid = low + (high - low) / 2;
    }

    return false;
  }
};

int main() {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 13;

  Solution *soln = new Solution();
  bool res = soln->searchMatrix(matrix, target);
  cout << "res: " << res << endl;
}
