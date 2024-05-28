#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {

    if (piles.size() == 1) {
      int res = piles[0] / h;
      if (piles[0] % h) {
        res++;
      }
      return res;
    }

    int max = *max_element(piles.begin(), piles.end());

    int low = 1;
    int high = max;
    int mid = (high - low) / 2;

    int current_slowest_speed = -1;

    while (low <= high) {
      if (mid == 0) {
        mid = low;
      }
      int hours = 0;
      for (int p : piles) {
        hours += p / mid;
        if (p % mid) {
          hours++;
        }
      }

      if (hours <= h) {
        current_slowest_speed = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }

      mid = low + (high - low) / 2;
    }

    return current_slowest_speed;
  }
};

int main() {
  vector<int> piles = {1000000000,1000000000};
  int h = 3;

  Solution *soln = new Solution();
  int res = soln->minEatingSpeed(piles, h);

  cout << "result: " << res << endl;
}
