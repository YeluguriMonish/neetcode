#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
  string minWindow(string s, string t) {
    int left = 0;
    int right = 0;
    int current_min = s.size() + 1;
    string res = "";

    unordered_map<char, int> target_map;
    unordered_map<char, int> current_map;

    for (char c : t) {
      target_map[c] += 1;
    }

    while (left < s.size()) {
      current_map[s[right]] += 1;

      if ((right - left) + 1 < t.size()) {
        right++;
        continue;
      }

      if (right == s.size()) {
        current_map.clear();
        left++;
        right = left;
        continue;
      }

      if (contains_target(target_map, current_map) &&
          ((right - left) + 1) < current_min) {
        do {
          current_min = right - left + 1;
          res = s.substr(left, ((right - left) + 1));
          current_map[s[left]]--;
          left++;
        } while(contains_target(target_map, current_map) && left < right);
        current_map.clear();
        left = right;
        continue;
      }

      right++;
    }

    return res;
  }

private:
  bool contains_target(unordered_map<char, int> &target_map,
                       unordered_map<char, int> &current_map) {
    for (auto const &pair : target_map) {
      if (pair.second > current_map[pair.first]) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";

  Solution *soln = new Solution();
  string res = soln->minWindow(s, t);
  cout << "result: " << res << endl;
}
