#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {

    if (s1.length() > s2.length()) {
      return false;
    }

    unordered_map<char, int> s1_char_count;
    for (char c : s1) {
      s1_char_count[c] += 1;
    }

    int left = 0;
    int right = s1.length() - 1;

    unordered_map<char, int> char_count_curr;

    for (int i = left; i <= right; i++) {
      char_count_curr[s2[i]] += 1;
    }

    while (right < s2.length()) {

      cout << "left: " << left << " right: " << right << endl;
      bool res = true;
      for (auto &pair : s1_char_count) {
        if (pair.second != char_count_curr[pair.first]) {
          res = false;
        }
      }

      if (res) {
        return true;
      }

      char_count_curr[s2[left]] -= 1;
      left++;
      right++;
      char_count_curr[s2[right]] += 1;
    }

    return false;
  }
};

int main() {
  string s1 = "adc";
  string s2 = "dcda";

  Solution *soln = new Solution();
  bool res = soln->checkInclusion(s1, s2);
  cout << "result: " << res << endl;
}
